#include "shmlib.h"


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

int shm_delete(shmid)
int shmid;
{
    if (shmctl(shmid, 0, IPC_RMID) == -1)
    {
        perror("shmctl()");

        return (-1);
    }

    return (0);
}

int shm_write(shmid, buf, buf_size)
int shmid;
char *buf;
int buf_size;
{
    char *shmaddr;

    shmaddr = shmat(shmid, (char *)0, 0);

    if (shmaddr == (char *)-1)
    {
        perror("shmat()");

        return (-1);
    }

    memcpy(shmaddr, buf, buf_size);

    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt()");

        return (-1);
    }

    return (0);
}

int shm_read(shmid, buf, buf_size)
int shmid;
char *buf;
int buf_size;
{
    char *shmaddr;

    shmaddr = shmat(shmid, (char *)0, 0);

    if (shmaddr == (char *)-1)
    {
        perror("shmat()");

        return (-1);
    }

    memcpy(buf, shmaddr, buf_size);

    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt()");

        return (-1);
    }

    return (0);
}