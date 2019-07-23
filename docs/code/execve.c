/*
 * execve() from command line.
 */
#include <getopt.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


struct {
    int envc;
    char* envs[256];
    int verbose;
} options;

void print_usage(FILE* stream, char* progname, int exit_status) {
    fprintf(stream, "usage: %s <options>\n", progname);
    exit(exit_status);
}


char** parse_arguments(int argc, char** argv) {
    char* progname = argv[0];
    /* A string listing valid short options letters.  */
    const char* const short_options = "he:v";
    /* An array describing valid long options.  */
    const struct option long_options[] = {
        { "help",     no_argument,       NULL, 'h' },
        { "env",      required_argument, NULL, 'e' },
        { "verbose",  0,                 NULL, 'v' },
        { NULL,       0,                 NULL,  0  }   /* Required at end of array.  */
    };

    int next_option;
    const char* output_filename = NULL;

    options.verbose = 0;
    options.envc = 0;

    do {
        next_option = getopt_long (argc, argv, short_options, long_options, NULL);
        switch (next_option) {
            case 'h':   /* -h or --help */
                /* User has requested usage information.  Print it to standard
                 *          output, and exit with exit code zero (normal termination).  */
                print_usage (stdout, progname, 0);

            case 'e':   /* -e or --env */
                /* This option takes an argument, the name of the output file.  */
                options.envs[options.envc] = strdup(optarg);
                options.envc++;
                break;

            case 'v':   /* -v or --verbose */
                options.verbose = 1;
                break;

            case '?':   /* The user specified an invalid option.  */
                /* Print usage information to standard error, and exit with exit
                 *          code one (indicating abonormal termination).  */
                print_usage (stderr, progname, 1);

            case -1:    /* Done with options.  */
                break;

            default:    /* Something else: unexpected.  */
                abort ();
        }
    }
    while (next_option != -1);

    return argv + optind;
}

int main(int argc, char* argv[], char* envp[]) {
    argv = parse_arguments(argc, argv);

    char* pathname = argv[0];
    char** new_argv = &argv[1];

    fprintf(stderr, "pathname='%s'\n", pathname);
    fprintf(stderr, "argv[0]='%s'\n", new_argv[0]);

    fprintf(stderr, " --- execve(%s) ---\n", pathname);

    int fd = open(pathname, O_RDONLY);
    if (fd == -1) {
        perror("open()");
        exit(-2);
    }

    fexecve(fd, new_argv, options.envs);

    perror("execve");

    return -1;
}
