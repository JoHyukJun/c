#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY_FILEPATH        "./shm"
#define SHMKEY_PROJID          'j'
#define PAGE_SIZE              1024

#define ROUNDUP(x)             (((x) + (PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1))


struct log_info {
    int     pid;
    int     count;
};

static void usage(const char *prog)
{
    printf("%s (monitor)\n", prog);
}

static int proc_monitoring(void)
{
    int n;
    int shmid;
    key_t key;
    size_t sz;
    struct log_info *log;
    struct log_info local;

    /*
    *   create shared memory
    */
    key = ftok(SHMKEY_FILEPATH, SHMKEY_PROJID);

    if (key == -1) {
        perror("ftok()");

        return (-1);
    }

    sz = ROUNDUP(sizeof(struct log_info));

    shmid = shmget(key, sz, IPC_CREAT | 0644);

    if (shmid == -1) {
        perror("shmget()");

        return(-1);
    }

    log = shmat(shmid, NULL, 0);

    if (log == (void *)-1) {
        perror("shmat()");

        return (-1);
    }

    memset(log, 0x00, sizeof(struct log_info));
    
    /*
    *   monitoring
    */
    n = 0;
    memset(&local, 0x00, sizeof(local));

    while(1) {
        sleep(1);

        if (memcmp(log, &local, sizeof(struct log_info)) != 0) {
            printf("log:pid[%d]:count[%d]\n", log->pid, log->count);

            memcpy(&local, log, sizeof(struct log_info));

            n++;
        }

        if (n == 5) break;
    }

    shmdt(log);

    return (0);
}

static int proc_log(void)
{
    int shmid;
    key_t key;
    size_t sz;
    struct log_info *log;

    /*
    *   create shared memory
    */
    key = ftok(SHMKEY_FILEPATH, SHMKEY_PROJID);

    if (key == -1) {
        perror("ftok()");

        return (-1);
    }

    sz = ROUNDUP(sizeof(struct log_info));

    shmid = shmget(key, sz, 0644);

    if (shmid == -1) {
        perror("shmget()");

        return(-1);
    }

    log = shmat(shmid, NULL, 0);

    if (log == (void *)-1) {
        perror("shmat()");

        return (-1);
    }

    log->pid = getpid();
    log->count++;

    shmdt(log);

    return (0);
}

int main(int argc, char **argv)
{
    int monitor = 0;

    if (argc == 2) {
        if (!strcmp(argv[1], "monitor")) {
            monitor = 1;
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
        proc_log();
    }

    return (0);
}