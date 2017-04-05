/**
 * $ ./ptrace_on_segfault  ./i_crash 265
 * RIP: 41414141 Instruction executed: ffffffff 11
 *  [I] child 17148 received signal 11
 *
 * <http://stackoverflow.com/questions/16291972/why-couldnt-i-intercept-segfault-signal-of-a-child-process>
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <inttypes.h>
#include <wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/syscall.h>
#include <capstone/capstone.h>

# define is_only_ptrace(s) (s != 5)

struct breakpoints_t {
    uint8_t size;
    uint32_t* addresses;
};

void breakpoints_add(struct breakpoints_t* b, uint32_t address) {
    unsigned int new_size = b->size + 1;
    uint32_t* new_addresses = (uint32_t*)realloc(b->addresses, new_size * sizeof(struct breakpoints_t));

    new_addresses[b->size] = address;

    b->size = new_size;
    b->addresses = new_addresses;

    fprintf(stderr, " [I] added breakpoint %p\n", address);
}

enum bp_check_result {
    BP_FOUND,
    BP_NOT_FOUND
};

int bp_check(struct breakpoints_t b, uint32_t address) {
    unsigned int idx = 0;
    for (idx = 0 ; idx < b.size ; idx++) {
        if (address == b.addresses[idx])
            return BP_FOUND;
    }

    return BP_NOT_FOUND;
}

/*
 * http://www.capstone-engine.org/lang_c.html
 */
int disassemble(uint8_t* code, unsigned int codesize, uint64_t address) {
    csh handle;
    cs_insn *insn;
    size_t count;

    if (cs_open(CS_ARCH_ARM, CS_MODE_32, &handle) != CS_ERR_OK) { // FIXME: make configurable
        return -1;
    }

    count = cs_disasm(handle, code, codesize, address, 0, &insn);
    if (count > 0) {
        size_t j;
        for (j = 0; j < count; j++) {
            printf("0x%"PRIx64":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic,
                    insn[j].op_str);
        }

        cs_free(insn, count);
    } else
        printf("ERROR: Failed to disassemble given code!\n");

    cs_close(&handle);

    return 0;
}

int usage(char* progname) {
    fprintf(
        stderr,
        "usage: %s [-b | -h]cmd\n"
        "\n\n-b <address>\tadd breakpoint\n", progname);
    exit(1);
}

int main(int argc, char* argv[]) {
    pid_t child;

    if (argc == 1) {
        usage(argv[0]);
    }

    char opt;
    uint32_t address;

    struct breakpoints_t breakpoints;
    breakpoints.size = 0;
    breakpoints.addresses = NULL;

    while ((opt = getopt(argc, argv, "hb:"))!= -1){
        switch(opt) {
            case 'h':
                usage(argv[0]);
                break;
            case 'b':
                address = strtoll(optarg, NULL, 16);
                breakpoints_add(&breakpoints, address);
                break;
            }
    }

    child = fork();

    if (child == 0) {
        /*
         * As soon as the child makes a call to any of the exec() functions, it receives a SIGTRAP,
         * at which point it is stopped until the tracing parent allows it to continue. It is
         * important for the parent to wait for this event to happen before performing any ptrace
         * operations, including the configuration operations involved with PTRACE_SETOPTIONS.
         */
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);

        fprintf(stderr, " [I] launching %s\n", argv[optind]);

        int err = execvp(argv[optind], argv + optind);

        if (err < 0) {
            perror("execvp");
            exit(2);
        }
    }

    int status;

    struct user_regs regs;
    long ins;

    while(1) {
        int signal = -1;
        wait(&status);

        if(WIFEXITED(status)) {
            fprintf(stderr, " [I] child %d exit with status %d\n", child, status);
            break;
        }

        if (WIFSTOPPED(status)) {
            signal = WSTOPSIG(status);
            //break;
        }

        // retrieve the info about registers
        ptrace(PTRACE_GETREGS, child, NULL, &regs);

        // retrieve info about code
        ins = ptrace(PTRACE_PEEKTEXT, child, regs.uregs[REG_R15], NULL);

        // TODO: use breakpoint to stop, using bp_check() is a performance hit
        if (is_only_ptrace(signal) || (bp_check(breakpoints, regs.uregs[REG_R15]) == BP_FOUND)) {
            // retrieve the signal infos (man sigaction)
            siginfo_t si;
            ptrace(PTRACE_GETSIGINFO, child, NULL, &si);

            // print all the infos
            printf("RIP: %08lx Instruction " "executed: %lx %d\n",
                    regs.uregs[REG_R15], ins, signal);
            printf("lr: %08lx\tsp: %lx\n", regs.uregs[REG_R14], regs.uregs[REG_R13]);
            printf("r0: %08lx\tr1: %08lx\n", regs.uregs[REG_R0], regs.uregs[REG_R1]);

            disassemble((uint8_t*)&ins, sizeof(ins), regs.uregs[REG_R15]);

            fprintf(stderr, " [I] child %d received signal %d at address %p\n", child, signal, si.si_addr);

            if (is_only_ptrace(signal))
                break;
        }

        ptrace(PTRACE_SINGLESTEP, child, NULL, NULL);
    }

    return 0;
}

