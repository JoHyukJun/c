#ifndef __SEMLIB__
#define __SEMLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_SET_LEN         1

int print_semlib();
int sem_open(key_t key);

#endif