#ifndef __FILELIB__
#define __FILELIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>


int print_filelib();
int fexist(const char *filename);
int ferase(const char *filename);
int fcopy(const char *src_filename, const char *dst_filename);
int funlink(const char *filename);
int get_filesize(const char *filename, long *filesize);
int init_seqnof(const char *filename);
int get_seqnof(const char *filename, int seqno);
int set_seqnof(const char *filename, int seqno);

#endif