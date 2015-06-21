/**
 *
 * LIBC_FATAL_STDERR_=1 makes the backtrace to be printed on stderr
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[]) {
    unsigned int count = 264;

    int std = 0;
    char opt;

    while ((opt = getopt(argc, argv, "ic:"))!= -1){
        switch(opt) {
            case 'i':
                std = 1;
                break;
            case 'c':
                count = atoi(optarg);
                break;
        }
    }

    char buffer[256];

    if (std) {
        gets(buffer);
    } else {
        memset(buffer, 'A', count);
    }

    printf(buffer);

    return 0;
}
