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

    key = ftok(FTOK_PATH, FTOK_PROJ_ID);

    if (key == -1) {
        perror("ftok()");

        return (-1);
    }

    semid = semget(key, SEM_SET_LEN, IPC_CREAT | 0644);

    if (semid == -1) {
        perror("semget()");

        return (-1);
    }

    return (semid);
}

int main()
{
    printf("TEST\n");
}