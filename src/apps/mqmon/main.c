#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define MSGSZ 1024

volatile sig_atomic_t stop = 0;

void handle_sigint(int sig) {
    stop = 1;
}

void print_msg_queue_info(int msqid) {
    struct msqid_ds buf;

    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl IPC_STAT");
        return;
    }

    printf("Queue ID: %d\n", msqid);
    printf(" - Owner UID: %u\n", buf.msg_perm.uid);
    printf(" - Owner GID: %u\n", buf.msg_perm.gid);
    printf(" - Current # of bytes: %lu\n", buf.msg_cbytes);
    printf(" - # of messages: %lu\n", buf.msg_qnum);
    printf(" - Max # of bytes: %lu\n", buf.msg_qbytes);
    printf(" - Last send time: %s", ctime(&buf.msg_stime));
    printf(" - Last receive time: %s", ctime(&buf.msg_rtime));
    printf(" - Last change time: %s", ctime(&buf.msg_ctime));
    printf("-----------------------------\n");
}

void clear_msg_queue(int msqid) {
    struct {
        long mtype;
        char mtext[MSGSZ];
    } msg;

    int removed = 0;

    while (1) {
        ssize_t ret = msgrcv(msqid, &msg, MSGSZ, 0, IPC_NOWAIT);
        if (ret == -1) {
            if (errno == ENOMSG) {
                break; // 큐가 비어 있음
            } else {
                perror("msgrcv");
                break;
            }
        }
        removed++;
    }

    printf("[✔] Cleared %d messages from the queue.\n", removed);
}

int main() {
    key_t key;
    int msqid;
    char command[16];

    signal(SIGINT, handle_sigint); // Ctrl+C 시 종료 플래그 설정

    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("Monitoring message queue with ID: %d\n", msqid);
    printf("Type 'clear' to clear the queue or 'quit' to exit.\n\n");

    while (!stop) {
        print_msg_queue_info(msqid);

        printf("[command]> ");
        fflush(stdout);

        // Non-blocking user input (with timeout using select)
        fd_set fds;
        struct timeval timeout = {2, 0}; // 2초

        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);

        int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &timeout);

        if (ret > 0 && FD_ISSET(STDIN_FILENO, &fds)) {
            if (fgets(command, sizeof(command), stdin) != NULL) {
                command[strcspn(command, "\n")] = 0; // 개행 제거
                if (strcmp(command, "clear") == 0) {
                    clear_msg_queue(msqid);
                } else if (strcmp(command, "quit") == 0) {
                    printf("Exiting.\n");
                    break;
                } else {
                    printf("Unknown command: %s\n", command);
                }
            }
        }
    }

    return 0;
}
