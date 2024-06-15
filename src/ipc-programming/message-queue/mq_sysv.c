#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MQ_KEY      "./"
#define MQ_KEY_ID   'j'
#define MSGBUF_SZ   128

struct msgbuf {
    long mtype;
    char buf[MSGBUF_SZ];
};

static void usage(const char *prog)
{
    printf("%s (send|revc) MTYPE\n", prog);
}

static int proc_init(void)
{
    int msgq;
    key_t key;

    key = ftok(MQ_KEY, MQ_KEY_ID);

    if (key == -1) {
        perror("ftok()");

        return (-1);
    }

    msgq = msgget(key, 0644 | IPC_CREAT);

    if (msgq == -1) {
        perror("msgget()");

        return (-1);
    }

    return msgq;
}

static int proc_send(long mtype)
{
    int msgq;
    struct msgbuf mbuf;

    msgq = proc_init();

    if (msgq == -1) {
        perror("proc_init()");

        return (-1);
    }

    memset(&mbuf, 0x00, sizeof(mbuf));
    mbuf.mtype = mtype;
    snprintf(mbuf.buf, sizeof(mbuf.buf), "hello there:mtype:[%ld]", mtype);

    if (msgsnd(msgq, &mbuf, sizeof(mbuf.buf), 0) == -1) {
        perror("msgsnd()");

        return (-1);
    }

    return (0);
}

static int proc_recv(long mtype)
{
    int retval;
    int msgq;
    struct msgbuf mbuf;

    msgq = proc_init();

    if (msgq == -1) {
        perror("proc_init()");

        return (-1);
    }

    memset(&mbuf, 0x00, sizeof(mbuf));

    retval = msgrcv(msgq, &mbuf, sizeof(mbuf.buf), mtype, 0);

    if (retval == -1) {
        perror("msgrcv()");

        return (-1);
    }

    printf("proc_recv: mtype:[%ld]: buf:[%s]\n", mbuf.mtype, mbuf.buf);

    return (0);
}

int main(int argc, char **argv)
{
    int     retval;
    long    mtype;

    if (argc < 3) {
        usage(argv[0]);

        return (-1);
    }

    mtype = strtol(argv[2], NULL, 10);

    if (!strcmp(argv[1], "send")) {
        if (mtype <= 0) {
            usage(argv[0]);

            return (-1);
        }
        retval = proc_send(mtype);

        if (retval == -1) {
            perror("proc_send()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "recv")) {
        retval = proc_recv(mtype);

        if (retval == -1) {
            perror("proc_recv()");

            return (-1);
        }
    }
    else {
        usage(argv[0]);
    }

    return (0);
}