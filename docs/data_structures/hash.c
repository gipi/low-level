/**
 * http://opendatastructures.org/ods-python.pdf
 *
 * Pg 104
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

uint32_t hash(uint32_t z, size_t size, uint32_t x) {
    return z*x >> (32 - size);
}

uint32_t hash_fixed(size_t size, uint32_t x) {
    return hash(2654435769UL, size, x);
}

int main(int argc, char* argv[]) {
    printf("%0u\n", hash_fixed(8, atoi(argv[1])));
    return 0;
}
