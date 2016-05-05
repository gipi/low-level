/**
 * Simple loader for 32 bit code. Pass the stdout file descriptor as
 * argument of the shellcode.
 *
 *   $ gcc -Wall -m32 loader.c -o loader
 */
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: %s <shellcode>\n", argv[0]);
    exit(1);
  }
  int (*fp)(int sock);
  void *mem = mmap(0, 0x1000, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
  memcpy(mem, argv[1], strlen(argv[1]));
  fp = (int(*)(int sock))mem;


  (int)(*fp)(1);
}
