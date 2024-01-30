#include "../lib/log.h"

int fd_log;

ssize_t write_on_log(char *msg, int size) {
    ssize_t c_write = 0;
    if ((c_write = write(fd_log, msg, size)) == -1)
        perror("log: write on log");

    return c_write;
}

void open_log() {
    fd_log = open(LOGPATH, O_CREAT | O_WRONLY | O_TRUNC, S_IREAD + S_IWUSR + S_IROTH + S_IRGRP);

    if (fd_log == -1) {
        perror("log: open");
        exit(EXIT_FAILURE);
    }

    write_on_log("log: start\n", sizeof("log: start"));
}

int open_pipe() {
    unlink(LOGPIPE);
    // S_IREAD = S_IRUSR & S_IWRITE = S_IWUSR;
    if (mknod(LOGPIPE, S_IFIFO | S_IREAD | S_IWRITE, 0) == -1) {
        perror("log: mknod");
    }

    write_on_log("log: mknod\n", sizeof("log: mknod"));

    int fd = open(LOGPIPE, O_RDONLY);
    if (fd == -1) {
        char failure_msg[] = "log: open %s failure\n", *msg = (char *) calloc(sizeof(failure_msg) + sizeof(LOGPIPE),
                                                                              sizeof(char));
        int size = sprintf(msg, failure_msg, LOGPIPE);

        write_on_log(msg, size);

        perror(msg);
    }

    write_on_log("log: pipe open\n", sizeof("log: pipe open"));

    return fd;
}

int main(int argc, char **argv) {
    open_log();

    int fd_pipe = open_pipe();

    return EXIT_SUCCESS;
}
