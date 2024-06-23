#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/file.h>

#define FLOCK_FILENAME      "./.flock_test"


static void usage(const char *prog)
{
    printf("%s (sh|ex)\n", prog);
}

int main(int argc, char **argv)
{
    int fd;
    int ops;

    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "sh")) {
        ops = LOCK_SH;
    }
    else if (!strcmp(argv[1], "ex")) {
        ops = LOCK_EX;
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    fd = open(FLOCK_FILENAME, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("open()");

        return (-1);
    }

    /* lock */
    printf("lock on\n");
    if (flock(fd, ops) == -1) {
        perror("flock()");
        close(fd);

        return (-1);
    }

    /* wait */
    printf("waiting for enter...\n");
    getc(stdin);

    /* unlock */
    if (flock(fd, LOCK_UN) == -1) {
        perror("flock()");
        close(fd);

        return (-1);
    }

    close(fd);

    return (0);
}