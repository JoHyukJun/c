#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define LOCK_FILENAME      "./.fcntl_test"
#define FILE_SIZE           1024
#define SECTION_LEN         4


static void usage(const char *prog)
{
    printf("%s (R|W) SECTION_IDX\n", prog);
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
    struct flock    fl;

    memset(&fl, 0x00, sizeof(fl));

    if (argc < 3) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "R")) {
        fl.l_type = F_RDLCK;
    }
    else if (!strcmp(argv[1], "W")) {
        fl.l_type = F_WRLCK;
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

    fl.l_whence = SEEK_SET;
    fl.l_start = (FILE_SIZE / SECTION_LEN) * s_idx;
    fl.l_len = (FILE_SIZE / SECTION_LEN);

    /* lock */
    printf("lock on\n");
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl()");
        close(fd);

        return (-1);
    }

    /* wait */
    printf("waiting for enter...\n");
    getc(stdin);

    /* unlock */
    if (fcntl(fd, F_UNLCK, &fl) == -1) {
        perror("fcntl()");
        close(fd);

        return (-1);
    }

    close(fd);

    return (0);
}