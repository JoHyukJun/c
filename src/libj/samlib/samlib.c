#include "samlib.h"


int print_samlib()
{
    printf("SAMLIB\n");

    return 0;
}

int shm_open(key)
key_t key;
{
    int shmid;

    shmid = shmget(key, SHM_SET_LEN, IPC_CREAT | 0644);

    if (shmid == -1)
    {
        perror("shmget()");

        return (-1);
    }

    return (shmid);
}

int shm_create(key)
key_t key;
{
    int shmid;

    shmid = shmget(key, SHM_SET_LEN, IPC_CREAT | IPC_EXCL | 0644);

    if (shmid == -1 && errno == EEXIST)
    {
        shmid = shmget(key, SHM_SET_LEN, 0);

        if (shmid == -1)
        {
            perror("shmget()");

            return (-1);
        }
    }

    return (shmid);
}