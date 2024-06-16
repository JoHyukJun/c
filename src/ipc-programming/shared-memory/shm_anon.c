#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define FORK_NUM        5


struct log_info {
    int     pid;
    int     count;
};

struct log_info *log_info_init(void)
{
    struct log_info *log;

    log = mmap(NULL, sizeof(struct log_info), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    if (log == MAP_FAILED) {
        perror("mmap()");

        return (NULL);
    }

    memset(log, 0x00, sizeof(struct log_info));

    return log;
}

static int proc_monitoring(struct log_info *log)
{
    int n;
    struct log_info local;

    n = 0;
    memset(&local, 0x00, sizeof(local));

    while(1) {
        usleep(1000);

        if (memcmp(log, &local, sizeof(struct log_info)) != 0) {
            printf("log:pid[%d]:count[%d]\n", log->pid, log->count);

            memcpy(&local, log, sizeof(struct log_info));

            n++;
        }

        if (n == 5) break;
    }

    munmap(log, sizeof(struct log_info));

    return (0);
}

static int proc_log(int idx, struct log_info *log)
{
    sleep(idx + 1);

    log->pid = getpid();
    log->count++;

    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int pid;
    struct log_info *log;

    log = log_info_init();

    if (!log) {
        perror("log_info_init()");

        return (-1);
    }

    for (i = 0; i < FORK_NUM; i++) {
        pid = fork();

        if (pid > 0) {
            /* parent */
        }
        else if (pid == 0) {
            /* child */
            proc_log(i, log);
            munmap(log, sizeof(struct log_info));

            return (0);
        }
        else {
            perror("fork()");

            return (-1);
        }
    }
    
    proc_monitoring(log);

    for (i = 0; i < FORK_NUM; i++) {
        pid = wait(NULL);

        printf("pid[%d] done...\n", pid);
    }

    return (0);
}