#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SEM_ID      "/jsem_id"


static void usage(const char *prog)
{
    printf("%s (view|wait|tryw|timedw|release)\n", prog);
}

static sem_t *init_semaphore(void)
{
    sem_t *sem;

    /* counting semaphore */
    sem = sem_open(SEM_ID, O_CREAT, 0644, 3);

    if (sem == SEM_FAILED) {
        perror("sem_open()");

        return (NULL);
    }

    return (sem);
}

static int sem_posix_view(sem_t *sem)
{
    int sval;

    if (sem_getvalue(sem, &sval) == -1) {
        perror("sem_getvalue()");

        return (-1);
    }

    printf("semaphore = %d\n", sval);

    return (0);
}

static int sem_posix_wait(sem_t *sem)
{
    if (sem_wait(sem) == -1) {
        perror("sem_wait()");

        return (-1);
    }

    return (0);
}

static int sem_posix_tryw(sem_t *sem)
{
    if (sem_trywait(sem) == -1) {
        perror("sem_wait()");

        return (-1);
    }

    return (0);
}

static int sem_posix_timedw(sem_t *sem)
{
    struct timespec ts;

    ts.tv_sec = 3;
    ts.tv_nsec = 0;

    if (sem_timedwait(sem, &ts) == -1) {
        perror("sem_wait()");

        return (-1);
    }

    return (0);
}

static int sem_posix_release(sem_t *sem)
{
    if (sem_post(sem) == -1) {
        perror("sem_post()");

        return (-1);
    }

    return (0);
}

int main(int argc, char **argv)
{
    int retval;
    sem_t *sem;

    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    sem = init_semaphore();

    if (sem == NULL) {
        perror("init_semaphore()");

        return (-1);
    }

    if (!strcmp(argv[1], "view")) {
        retval = sem_posix_view(sem);

        if (retval != 0) {
            perror("sem_posix_view()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "wait")) {
        retval = sem_posix_wait(sem);

        if (retval != 0) {
            perror("sem_posix_wait()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "tryw")) {
        retval = sem_posix_tryw(sem);

        if (retval != 0) {
            perror("sem_posix_tryw()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "timedw")) {
        retval = sem_posix_timedw(sem);

        if (retval != 0) {
            perror("sem_posix_timedw()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "release")) {
        retval = sem_posix_release(sem);

        if (retval != 0) {
            perror("sem_posix_release()");

            return (-1);
        }
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    return (0);
}