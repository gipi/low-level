/**
 * Simple payload executer.
 *
 * Mmaps the file containing the payload and then calls it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        exit(0);
    }
    int fd = open(argv[1], O_RDONLY);

    if (fd < 0) {
        perror(" [!] error opening file");
        exit(1);
    }

    // TODO: make possible to configure RWX via command line
    void (*exploit)(void) = mmap(NULL, 4096, PROT_EXEC | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (exploit == MAP_FAILED) {
        perror(" [!] failing at mmaping");
        exit(2);
    }

    fprintf(stderr, " [I] executing at %p\n", exploit);
    exploit();

    return 0;
}
