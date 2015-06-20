#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) {

    unsigned int count = 600;

    if (argc > 1) {
        count = atoi(argv[1]);
    }
    char buffer[256];

    memset(buffer, 'A', count);

    printf(buffer);

    return 0;
}
