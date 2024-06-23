#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>

#define SHM_NAME        "/jshm"


struct log_info {
    sem_t   sem;
    int     pid;
    int     count;
};

static void usage(const char *prog)
{
    printf("%s (monitor|get|put)\n", prog);
}

static int proc_monitoring(void)
{
    int fd;
    int n;
    int sval;
    struct log_info *log;
    struct log_info local;

    fd = shm_open(SHM_NAME, O_RDWR | O_CREAT, 0644);

    if (fd == -1) {
        perror("shm_open()");

        return (-1);
    }

    if (ftruncate(fd, sizeof(struct log_info)) == -1) {
        perror("ftruncate()");
        close(fd);

        return (-1);
    }

    log = mmap(NULL, sizeof(struct log_info), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (log == MAP_FAILED) {
        perror("mmap()");
        close(fd);

        return (-1);
    }

    memset(log, 0x00, sizeof(struct log_info));

    /* counting semaphore */
    if (sem_init(&log->sem, 1, 3) == -1) {
        perror("sem_init()");
        close(fd);

        return (-1);
    }

    close(fd);

    n = 0;
    memset(&local, 0x00, sizeof(local));

    while(1) {
        sleep(1);

        if (memcmp(log, &local, sizeof(struct log_info)) != 0) {
            if (sem_getvalue(sem, &sval) == -1) {
                perror("sem_getvalue()");

                return (-1);
            }
            printf("log:pid[%d]:count[%d]:sem[%d]\n", log->pid, log->count, sval);

            memcpy(&local, log, sizeof(struct log_info));

            n++;
        }

        if (n == 5) break;
    }

    sem_destroy(&log->sem);
    munmap(log, sizeof(struct log_info));

    return (0);
}

static int proc_log(void)
{
    int fd;
    struct log_info *log;

    fd = shm_open(SHM_NAME, O_RDWR, 0644);

    if (fd == -1) {
        perror("shm_open()");

        return (-1);
    }

    log = mmap(NULL, sizeof(struct log_info), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (log == MAP_FAILED) {
        perror("mmap()");
        close(fd);

        return (-1);
    }

    close(fd);

    print("logger pid:[%d]\n", getpid());

    sem_wait(&log->sem);

    log->pid = getpid();
    log->count++;

    sem_post(&log->sem);

    munmap(log, sizeof(struct log_info));

    return (0);
}

static int proc_release(void)
{
    int fd;
    struct log_info *log;

    fd = shm_open(SHM_NAME, O_RDWR, 0644);

    if (fd == -1) {
        perror("shm_open()");

        return (-1);
    }

    log = mmap(NULL, sizeof(struct log_info), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (log == MAP_FAILED) {
        perror("mmap()");
        close(fd);

        return (-1);
    }

    close(fd);

    sem_post(&log->sem);

    munmap(log, sizeof(struct log_info));

    return (0);

}

int main(int argc, char **argv)
{
    int monitor = 0;
    int get = 0;

    if (argc == 2) {
        if (!strcmp(argv[1], "monitor")) {
            monitor = 1;
        }
        else if (!strcmp(argv[1], "get")) {
            get = 1;
        }
        else if (!strcmp(argv[1], "put")) {
            get = 0;
        }
        else {
            usage(argv[0]);

            return (-1);
        }
    }
    else if (argc > 2) {
        usage(argv[0]);

        return (-1);
    }

    if (monitor) {
        proc_monitoring();
    }
    else {
        if (get) {
            proc_log();
        }
        else {
            proc_release();
        }
    }

    return (0);
}