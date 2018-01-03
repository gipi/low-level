#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int pipein[2];
    int pipeout[2];

    int r;

    r = pipe(pipein);
    if (r) {
        perror("pipe");
        exit(1);
    }

    r = pipe(pipeout);
    if (r) {
        perror("pipe");
        exit(1);
    }

    pid_t child = fork();
    if (child == 0) { /* CHILD */
        close(pipein[1]); /* close pipe write end */
        dup2(pipein[0], STDIN_FILENO);
        close(pipeout[0]);
        dup2(pipeout[1], STDOUT_FILENO);

        char* _argv[] = {
            "bash",
            "-c",
            "id",
            NULL
        };
        execve("/bin/bash", _argv, NULL);
    }

    char buff[1024];

    int n = read(pipeout[0], buff, 1024);
    if (n == 0) {
        perror("read()");
        exit(2);
    }
    printf("id: %s\n", buff);
}
