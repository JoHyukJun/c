#include "loglib.h"


FILE *log_fp = NULL;

int print_loglib()
{
    printf("LOGLIB\n");

    return 0;
}

FILE *get_logfile_ptr(filename)
const char *filename;
{
    FILE *fp;

    fp = fopen(filename, "a");

    if (fp == NULL)
    {
        perror("fopen()");

        return (NULL);
    }

    return (fp);
}

int set_logfile_ptr(fp)
FILE *fp;
{
    log_fp = fp;

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

int log_write(fd, buf)
int fd;
const char *buf;
{
    int write_size;
    struct timeval tv;
    int hour, min, sec;

    gettimeofday(&tv, NULL);

    hour = tv.tv_sec / 3600 % 24;
    min = tv.tv_sec / 60 % 60;
    sec = tv.tv_sec % 60;

    write_size = dprintf(fd, "[%02d:%02d:%02d] %s", hour, min, sec, buf);

    write_size += write(fd, "\n", 1);

    if (write_size == -1)
    {
        perror("write()");

        return (-1);
    }

    return (write_size);
}

int debug(const char *fmt, ...)
{
    va_list ap;
    char buf[1024];
    int len;

    va_start(ap, fmt);
    len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    if (len == -1)
    {
        perror("vsnprintf()");

        return (-1);
    }

    if (log_fp == NULL)
    {
        perror("log_fp is NULL");

        return (-1);
    }

    if (log_write(fileno(log_fp), buf) < 0)
    {
        return (-1);
    }

    return (0);
}
