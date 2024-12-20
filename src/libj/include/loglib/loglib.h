#ifndef __LOGLIB__
#define __LOGLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>


extern FILE *log_fp;

int print_loglib();
FILE *get_logfile_ptr(const char *filename);
int log_open(const char *filename);
int log_close(int fd);
int log_write(int fd, const char *buf, int size);
int debug(const char *fmt, ...);


#endif