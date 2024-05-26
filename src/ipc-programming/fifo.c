#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_FILENAME       "./jfifo"


static void usage(char *prog) {
    printf("%s w|r\n", prog);

    return;
}

static int proc_reader(void) {
    int     fd;
    char    buf[1024];

    fd = open(FIFO_FILENAME, O_RDONLY);

    if (fd < 0) {
        perror("open()");

        return (-1);
    }

    read(fd, buf, sizeof(buf));
    printf("READER...%s\n", buf);

    close(fd);

    return (0);
}

static int proc_writer(void) {
    int     fd;
    char    buf[1024];

    unlink(FIFO_FILENAME);

    if (mkfifo(FIFO_FILENAME, 0644)) {
        perror("mkfifo()");

        return (-1);
    }

    fd = open(FIFO_FILENAME, O_WRONLY);

    if (fd < 0) {
        perror("open()");

        return (-1);
    }

    strncpy(buf, "HELLO THERE", sizeof(buf));
    write(fd, buf, strlen(buf));
    close(fd);

    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "r")) {
        /*
            reader
        */
        proc_reader();
    }
    else if (!strcmp(argv[1], "w")) {
        /*
            writer
        */
       proc_writer();
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    return (0);
}
