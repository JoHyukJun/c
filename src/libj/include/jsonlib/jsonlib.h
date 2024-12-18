#ifndef __JSONLIB__
#define __JSONLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


int print_jsonlib();
int json_open(const char *filename);
int json_create(const char *filename);
int json_close(int fd);
int json_read(int fd, char *buf, int size);
int json_get_element(int fd, const char *key, char *value);
int json_set_element(int fd, const char *key, const char *value);

#endif