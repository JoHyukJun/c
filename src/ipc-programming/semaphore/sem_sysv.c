#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define FTOK_PATH           "/tmp"
#define FTOK_PROJ_ID        'd'
#define SEM_SET_LEN         2


static void usage(const char *prog)
{
    printf("%s (init|view|get SEM_IDX|release SEM_IDX|wait SEM_IDX)\n", prog);
}

static int init_semaphore(void)
{
    key_t key;
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

static int sem_sysv_init(int sem_id)
{
    /* binary semaphore */
    semctl(sem_id, 0, SETVAL, 1);
    /* counting semaphore */
    semctl(sem_id, 1, SETVAL, 3);

    return (0);
}

static int sem_sysv_view(int sem_id)
{
    int i;

    for (i = 0; i < SEM_SET_LEN; i++) {
        printf("semaphore[%d] = %d\n", i, semctl(sem_id, i, GETVAL));
    }

    return (0);
}

static int sem_sysv_get(int sem_id, int sem_idx)
{
    struct sembuf buff;

    memset(&buff, 0x00, sizeof(buff));

    buff.sem_num = sem_idx;
    buff.sem_op = -1;

    if (semop(sem_id, &buff, 1) == -1) {
        perror("semop()");

        return (-1);
    }

    return (0);
}

static int sem_sysv_release(int sem_id, int sem_idx)
{
    struct sembuf buff;

    memset(&buff, 0x00, sizeof(buff));

    buff.sem_num = sem_idx;
    buff.sem_op = 1;

    if (semop(sem_id, &buff, 1) == -1) {
        perror("semop()");

        return (-1);
    }

    return (0);
}

static int sem_sysv_wait(int sem_id, int sem_idx)
{
    struct sembuf buff;

    memset(&buff, 0x00, sizeof(buff));

    buff.sem_num = sem_idx;
    buff.sem_op = 0;

    if (semop(sem_id, &buff, 1) == -1) {
        perror("semop()");

        return (-1);
    }

    return (0);
}

int main(int argc, char **argv)
{
    int sem_id;
    int sem_idx;
    int retval;

    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    sem_id = init_semaphore();

    if (sem_id == -1) {
        perror("init_semaphore()");

        return (-1);
    }

    if (!strcmp(argv[1], "init")) {
        retval = sem_sysv_init(sem_id);

        if (retval != 0) {
            perror("sem_sysv_init()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "view")) {
        retval = sem_sysv_view(sem_id);

        if (retval != 0) {
            perror("sem_sysv_view()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "get")) {
        if (argc < 3) {
            usage(argv[0]);

            return (-1);
        }

        sem_idx = atoi(argv[2]);

        retval = sem_sysv_get(sem_id, sem_idx);

        if (retval != 0) {
            perror("sem_sysv_get()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "release")) {
        if (argc < 3) {
            usage(argv[0]);

            return (-1);
        }

        sem_idx = atoi(argv[2]);

        retval = sem_sysv_release(sem_id, sem_idx);

        if (retval != 0) {
            perror("sem_sysv_release()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "wait")) {
        if (argc < 3) {
            usage(argv[0]);

            return (-1);
        }

        sem_idx = atoi(argv[2]);

        retval = sem_sysv_wait(sem_id, sem_idx);

        if (retval != 0) {
            perror("sem_sysv_wait()");

            return (-1);
        }
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    return (0);
}