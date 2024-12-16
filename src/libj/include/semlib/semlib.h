#ifndef __SEMLIB__
#define __SEMLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_SET_LEN         1

int print_semlib();
int sem_open(key_t key);
int sem_create(key_t key);
int sem_delete(int semid);
int sem_v(int semid);
int sem_p(int semid);
int sem_lock(int semid);
int sem_unlock(int semid);

#endif