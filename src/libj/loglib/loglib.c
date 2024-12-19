#include "loglib.h"

int print_loglib()
{
    printf("LOGLIB\n");

    return 0;
}

int log_open(filename)
const char *filename;
{
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        perror("open()");

        return (-1);
    }

    return (fd);
}

int log_close(fd)
int fd;
{
    if (close(fd) == -1)
    {
        perror("close()");

        return (-1);
    }

    return (0);
}

int log_write(fd, buf, size)
int fd;
const char *buf;
int size;
{
    int write_size;

    write_size = write(fd, buf, size);

    if (write_size == -1)
    {
        perror("write()");

        return (-1);
    }

    return (write_size);
}

int log_write_str(fd, buf)
int fd;
const char *buf;
{
    int write_size;

    write_size = write(fd, buf, strlen(buf));

    if (write_size == -1)
    {
        perror("write()");

        return (-1);
    }

    return (write_size);
}
