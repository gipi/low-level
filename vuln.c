#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define SIZE 8192

char buf[SIZE];

struct foo {
    uint16_t miao;
};

void cpy(struct foo* p, int count) {
    int n = count * sizeof(struct foo);
    fprintf(stderr, "n=(%i) %u ", n, n);
    if ((n < SIZE) && (n > 0)) {
        fprintf(stderr, "copying");

        memcpy(buf, p, n);
    }
    fprintf(stderr, "\n");
}

int main(int argc, char* argv[]) {
    struct foo f = {
        .miao = 0xaa55
    };

    int count = atoi(argv[1]);

    cpy(&f, count);

    return 0;
}
