#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

int main(int argc, char* argv[]) {

    char* msg = argc > 1 ? argv[1] : "Hello world!";

    openlog("slog", LOG_PID|LOG_PERROR|LOG_CONS, LOG_USER); // FIXME: LOG_PERROR is not POSIX
    syslog(LOG_INFO, msg);
    closelog();

    return 0;
}

