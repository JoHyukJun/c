#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define POSIX_MQ_NAME   "/j"
#define MSGBUF_SZ       8192


static void usage(const char *prog)
{
    printf("%s (send priority|revc)\n", prog);
}

static int proc_init(void)
{
    mqd_t mqd
    struct mq_attr attr;

    memset(&attr, 0x00, sizeof(attr));
    mqd = mq_open(POSIX_MQ_NAME, O_RDWR | O_CREAT, 0644, NULL);

    if (mqd == -1) {
        perror("mq_open()");

        return (-1);
    }

    if (mq_getattr(mqd, &attr) == -1) {
        perror("mq_getattr()");
        close(mqd);

        return (-1);
    }

    printf("mq_flags = %ld\n", attr.mq_flags);
    printf("mq_maxmsg = %ld\n", attr.mq_maxmsg)
    printf("mq_msgsize = %ld\n", attr.mq_msgsize);
    printf("mq_curmsgs = %ld\n", attr.mq_curmsgs);
    
    return (mqd);
}

static int proc_send(unsigned int priority)
{
    int mqd;
    char buf[MSGBUF_SZ];

    memset(buf, 0, sizeof(buf));
    mqd = proc_init();

    if (mqd == -1) {
        perror("proc_init()");

        return (-1);
    }

    snprintf(buf, sizeof(buf), "HELLO THERE[%d]", getpid());

    if (mq_send(mqd, buf, sizeof(buf), priority) == -1) {
        perror("mq_send()");
        close(mqd);

        return (-1);
    }

    printf("PRI[%u],SEND[%s]\n", priority, buf);

    return (0);
}

static int proc_recv(void)
{
    int mqd;
    char mbuf[MSGBUF_SZ];
    unsigned int priority;

    memset(&mbuf, 0x00, sizeof(mbuf));
    mqd = proc_init();

    if (mqd == -1) {
        perror("proc_init()");

        return (-1);
    }

    if (mq_receive(mqd, buf, sizeof(buf), &priority) == -1) {
        perror("mq_reveive()");
        close(mqd);

        return (-1);
    }

    printf("PRI[%u],RECV[%s]\n", priority, buf);

    return (0);
}

int main(int argc, char **argv)
{
    int     retval;

    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "send")) {
        unsigned int priority;
        if (argc < 3) {
            usage(argv[0]);
        }
        priority = (unsigned int)strtoul(argv[2], NULL, 10);

        retval = proc_send(priority);

        if (retval == -1) {
            perror("proc_send()");

            return (-1);
        }
    }
    else if (!strcmp(argv[1], "recv")) {
        retval = proc_recv();

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