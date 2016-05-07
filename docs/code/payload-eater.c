/**
 * Simple payload executer.
 *
 * Mmaps the file containing the payload and then calls it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LISTEN_PORT 4444

struct _env {
    char* shellcode_filepath;
    int need_fd;
    int need_socket;
} env;


void print_usage (FILE* stream, char* progname, int exit_code) {
  fprintf (stream, "Usage:  %s options inputfile\n", progname);
  fprintf (stream,
           "  -h  --help             Display this usage information.\n"
           "  -f  --file-descriptor  pass stdout to the shellcode.\n"
           "  -s  --socket           pass socket to the shellcode.\n"
           "  -v  --verbose          Print verbose messages.\n");
  exit (exit_code);
}

// http://advancedlinuxprogramming.com/listings/chapter-2/getopt_long.c
void handle_options(int argc, char** argv, char* progname) {
    /* A string listing valid short options letters.  */
    const char* const short_options = "ho:v";
    /* An array describing valid long options.  */
    const struct option long_options[] = {
        { "help",            no_argument, NULL, 'h' },
        { "file-descriptor", no_argument, NULL, 'f' },
        { "socket",          no_argument, NULL, 's' },
        { "verbose",  0, NULL, 'v' },
        { NULL,       0, NULL, 0   }   /* Required at end of array.  */
    };

    int next_option;
    const char* output_filename = NULL;
    int verbose = 0;

    do {
        next_option = getopt_long (argc, argv, short_options, long_options, NULL);
        switch (next_option) {
            case 'h':   /* -h or --help */
                /* User has requested usage information.  Print it to standard
                 *          output, and exit with exit code zero (normal termination).  */
                print_usage (stdout, progname, 0);

            case 'f':   /* -o or --output */
                /* This option takes an argument, the name of the output file.  */
                env.need_fd = 1;
                break;

            case 's':   /* -o or --output */
                /* This option takes an argument, the name of the output file.  */
                env.need_socket = 1;
                break;

            case 'v':   /* -v or --verbose */
                verbose = 1;
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

    /* Done with options.  OPTIND points to first non-option argument.
     *      For demonstration purposes, print them if the verbose option was
     *           specified.  */

    if (optind == argc) {
        print_usage(stderr, progname, 1);
    }
    env.shellcode_filepath = argv[optind];
}

/**
 * This is a little more complex since we need to create a server that
 * listens to connection and executes the shellcode at the first connection.
 */
void exploit_w_socket(void (*exploit)(int socketfd)) {
    int ssock;
    struct sockaddr_in saddr;

  int csock;
  struct sockaddr_in caddr;
  socklen_t clen = sizeof(caddr);

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(LISTEN_PORT);

    if( (ssock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()"); 
        exit(1); 
    }

    int yes = 1;

    if(setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) <0) {
        perror("setsockopt()");
        exit(1);
    }


    if( bind(ssock, (struct sockaddr*) &saddr, sizeof(saddr)) < 0) { 
        perror("bind()"); 
        exit(1); 
    }

    if( listen(ssock, 5) < 0) { 
        perror("listen()"); 
        exit(1); 
    }

   if( (csock = accept(ssock, (struct sockaddr *) &caddr, &clen)) < 0) {
      perror("accept()");
      exit(1);
    }

    exploit(csock);
}

void jmp(void* shellcode) {
    __asm__(
        "jmp *%%rdi\n"
        :
        :
    );
}

int main(int argc, char** argv) {
    char* progname = argv[0];
    handle_options(argc, argv, progname);

    int fd = open(env.shellcode_filepath, O_RDONLY);

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

    if (env.need_fd) { // if the shellcode needs a file descriptor, pass the stdout
        fprintf(stderr, " [I] executing with stdout passed as first argument\n");
        void (*exploit_with_fd)(int fd) = exploit;
        exploit_with_fd(1);
    } else if (env.need_socket) {
        fprintf(stderr, " [I] executing with a socket passed as first argument\n");
        exploit_w_socket(exploit);
    } else {
        fprintf(stderr, " [I] executing with a simple jmp *%%rax\n");
        jmp(exploit);
    }

    fprintf(stderr, " [I] completed execution of %s\n", progname);

    return 0;
}
