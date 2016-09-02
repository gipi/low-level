#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned long get_esp(void) {
   __asm__("movl %esp,%eax");
}

void usage(char progname[]) {
    fprintf(stderr, "usage: %s /path/to/binary arg0 arg1 ...\n", progname);
}

void main(int argc, char *argv[]) {
    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }
    unsigned int offset = 0;
    long addr = get_esp() - offset;
    printf("Using address: 0x%x\n", addr);

    /*
     * We want to execute the program passed as argument.
     */
    int ret = execve(argv[1], argv + 1, NULL);

    perror(" [E] execve");

    return -2;
}
