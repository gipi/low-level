/*
 * Dump some useful infos.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/auxv.h>


unsigned long get_stack_pointer(void) {
#if __GNUC__
    #if __x86_64__
   __asm__("mov %rsp,%rax");
    #else
   __asm__("movl %esp,%eax");
   #endif
#endif
}

unsigned long get_thread_segment(void) {
#if __GNUC__
    #if __x86_64__
   __asm__("movl %fs:0,%eax");
    #else
   __asm__("movl %gs:0,%eax");
    #endif
#endif
}

char** get_last_envp(char* envp[]) {
    while(*envp++ != NULL); /*from stack diagram above: *envp = NULL marks end of envp*/

    return envp;
}

/* http://articles.manugarg.com/aboutelfauxiliaryvectors.html */
void dump_auxv(Elf64_auxv_t* auxv) {
    for (; auxv->a_type != AT_NULL; auxv++) /* auxv->a_type = AT_NULL marks the end of auxv */ {
        printf("type %d is: 0x%x\n", auxv->a_type, auxv->a_un.a_val);
    }
}

void usage(char progname[]) {
    fprintf(stderr, "usage: %s /path/to/binary arg0 arg1 ...\n", progname);
}

int main(int argc, char *argv[], char* envp[]) {
    int *rsp;

    printf("arg: %p argv[0]='%s'\n", argv, argv[0]);
    printf("env: %p\n", envp);
    printf("rsp: %p\n", &rsp);
#if 0
    while (*envp != NULL) {
        printf("%s\n", *envp);
        ++envp;
    }
#endif
    unsigned int offset = 0;
    long addr = get_stack_pointer() - offset;
    printf("Using esp address: 0x%lx\n", addr);
    printf("Using tls address: 0x%lx\n", get_thread_segment());

    Elf64_auxv_t* auxv = get_last_envp(envp);
    dump_auxv(auxv);

    return 0;
}
