/**
 * Need to bruteforce with static argument an executable?
 *
 * This is the right program for you!
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>


void launch(char** prog_args);

int main(int argc, char* argv[]) {
    char** prog_args = argv + 1;
    // infinite loop: we fork and exec
    while (1) {
        sleep(1);
        pid_t child = fork();

        if (child == 0) // child
            launch(prog_args);
    }

    return 0;
}

void launch(char* prog_args[]) {
    int err = execvp(prog_args[0], prog_args + 1);

    if (err < 0) {
        perror("execvp");
        exit(2);
    }
}
