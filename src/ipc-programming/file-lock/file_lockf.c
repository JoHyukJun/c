#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define LOCK_FILENAME      "./.lockf_test"
#define FILE_SIZE           1024
#define SECTION_LEN         4
#define SECTION_SIZE        (FILE_SIZE / SECTION_LEN)


static void usage(const char *prog)
{
    printf("%s (W) SECTION_IDX\n", prog);
}

static int open_file(void)
{
    int fd;

    fd = open(LOCK_FILENAME, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("open()");

        return (-1);
    }

    if (ftruncate(fd, FILE_SIZE) == -1) {
        perror("ftruncate()");
        close(fd);

        return (-1);
    }

    return (fd);
}

int main(int argc, char **argv)
{
    int             fd;
    int             s_idx;
    
    if (argc < 3) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "W")) {
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    s_idx = atoi(argv[2]);

    if (s_idx >= SECTION_LEN) {
        usage(argv[0]);

        return (-1);
    }

    fd = open_file();

    if (fd == -1) {
        perror("open_file()");
        close(fd);

        return (-1);
    }

    lseek(fd, SECTION_SIZE * s_idx, SEEK_SET);

    /* lock */
    printf("lock on\n");
    if (lockf(fd, F_LOCK, SECTION_SIZE) == -1) {
        perror("lockf()");
        close(fd);

        return (-1);
    }

    /* wait */
    printf("waiting for enter...\n");
    getc(stdin);

    /* unlock */
    if (lockf(fd, F_ULOCK, SECTION_SIZE) == -1) {
        perror("lockf()");
        close(fd);

        return (-1);
    }

    close(fd);

    return (0);
}