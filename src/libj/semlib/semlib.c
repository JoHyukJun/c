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

    if (semid == -1)
    {
        perror("semget()");

        return (-1);
    }

    return (semid);
}

int sem_create(key)
key_t key;
{
    int semid;
    union semun sem_union;

    semid = semget(key, SEM_SET_LEN, IPC_CREAT | IPC_EXCL | 0644);

    if (semid < 0)
    {
        if (errno == EEXIST)
        {
            semid = semget(key, SEM_SET_LEN, 0);

            if (semid < 0)
            {
                perror("semget()");

                return (-1 * errno);
            }
        }
        else
        {
            perror("semget()");

            return (-1 * errno);
        }
    }
    else
    {
        // Initialize the semaphore
        sem_union.val = 1;

        if (semctl(semid, 0, SETVAL, sem_union) == -1)
        {
            perror("semctl()");

            return (-1 * errno);
        }
    }

    return (semid);
}

int sem_delete(semid)
int semid;
{
    if (semctl(semid, 0, IPC_RMID) == -1)
    {
        perror("semctl()");

        return (-1 * errno);
    }

    return (0);
}

int sem_v(semid)
int semid;
{
    struct sembuf sb;

    sb.sem_num = 0;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;

    if (semop(semid, &sb, 1) == -1)
    {
        perror("semop()");

        return (-1 * errno);
    }

    return (0);
}

int sem_p(semid)
int semid;
{
    struct sembuf sb;

    sb.sem_num = 0;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;

    if (semop(semid, &sb, 1) == -1)
    {
        perror("semop()");

        return (-1 * errno);
    }

    return (0);
}

int sem_lock(semid)
int semid;
{
    if (sem_v(semid) < 0)
    {
        return (-1);
    }

    return (0);
}

int sem_unlock(semid)
int semid;
{
    if (sem_p(semid) < 0)
    {
        return (-1);
    }

    return (0);
}