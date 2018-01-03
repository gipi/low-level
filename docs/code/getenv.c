#include <stdio.h>
#include <stdlib.h>

#define SHELLCODE_ENV_NAME "EGG"

int main() {
    char* env = getenv(SHELLCODE_ENV_NAME);
    if (env == NULL) {
        fprintf(stderr, " [!] no "SHELLCODE_ENV_NAME" variable found\n");
        return 1;
    }

    fprintf(stderr, "%p", env);

    return 0;
}
