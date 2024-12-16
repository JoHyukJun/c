#include "semlib.h"


int print_semlib()
{
    printf("SEMLIB\n");

    return 0;
}

int sem_open(key)
key_t key;
{
    int semid;

    semid = semget(key, SEM_SET_LEN, IPC_CREAT | 0644);

    if (semid == -1) {
        perror("semget()");

        return (-1);
    }

    return (semid);
}

int sem_create(key)
key_t key;
{
    int semid;

    semid = semget(key, SEM_SET_LEN, IPC_CREAT | IPC_EXCL | 0644);

    if (semid == -1) {
        perror("semget()");

        return (-1);
    }

    return (semid);
}