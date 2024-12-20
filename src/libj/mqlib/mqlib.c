#include "mqlib.h")


int print_mqlib()
{
    printf("MQLIB\n");

    return 0;
}

int mq_open(key)
key_t key;
{
    int mqid;

    if ((mqid = msgget(key, IPC_CREAT | 0666)) == -1)
    {
        perror("msgget()");

        return (-1);
    }

    return (mqid);
}

int mq_delete(mqid)
int mqid;
{
    if (msgctl(mqid, IPC_RMID, 0) == -1)
    {
        perror("msgctl()");

        return (-1);
    }

    return (0);
}

int mq_send(mqid, msg, len)
int mqid;
const char *msg;
int len;
{
    if (msgsnd(mqid, msg, len, 0) == -1)
    {
        perror("msgsnd()");

        return (-1);
    }

    return (0);
}

int mq_recv(mqid, msg, len)
int mqid;
char *msg;
int len;
{
    if (msgrcv(mqid, msg, len, 0, 0) == -1)
    {
        perror("msgrcv()");

        return (-1);
    }

    return (0);
}

int mq_send_nowait(mqid, msg, len)
int mqid;
const char *msg;
int len;
{
    if (msgsnd(mqid, msg, len, IPC_NOWAIT) == -1)
    {
        perror("msgsnd()");

        return (-1);
    }

    return (0);
}

int mq_recv_nowait(mqid, msg, len)
int mqid;
char *msg;
int len;
{
    if (msgrcv(mqid, msg, len, 0, IPC_NOWAIT) == -1)
    {
        perror("msgrcv()");

        return (-1);
    }

    return (0);
}

int mq_send_block(mqid, msg, len)
int mqid;
const char *msg;
int len;
{
    if (msgsnd(mqid, msg, len, MSG_NOERROR) == -1)
    {
        perror("msgsnd()");

        return (-1);
    }

    return (0);
}

int mq_recv_block(mqid, msg, len)
int mqid;
char *msg;
int len;
{
    if (msgrcv(mqid, msg, len, 0, MSG_NOERROR) == -1)
    {
        perror("msgrcv()");

        return (-1);
    }

    return (0);
}

