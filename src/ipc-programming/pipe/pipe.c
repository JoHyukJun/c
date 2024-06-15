#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
    int pipe_fds[2];
    pid_t pid;
    char buf[1024];
    int wstatus;

    memset(buf, 0x00, sizeof(buf));

    printf("[%d]START...\n", getpid());

    if (pipe(pipe_fds)) {
        perror("pipe()");

        return (-1);
    }

    pid = fork();

    if (pid == 0) {
        /* child process */
        close(pipe_fds[1]);

        read(pipe_fds[0], buf, sizeof(buf));
        printf("[%d]FROM PARENT PROCESS...%s\n", getpid(), buf);

        close(pipe_fds[0]);
    }
    else if (pid > 0) {
        /* parent process */
        close(pipe_fds[0]);

        strncpy(buf, "HELLO THERE", sizeof(buf) - 1);
        write(pipe_fds[1], buf, strlen(buf));

        close(pipe_fds[1]);

        pid = wait(&wstatus);
    }
    else {
        /* error case */
        perror("fork()");

        goto err;
    }

err:
    close(pipe_fds[0]);
    close(pipe_fds[1]);

    return (0);
}
