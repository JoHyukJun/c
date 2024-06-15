#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PAHT     "./socket_stream_un"


static void usage(const char *prog)
{
    printf("%s (server|client)\n", prog);
}

int stream_recv(int socket_fd, void *buf, size_t buflen, int flag)
{
    int retval;
    int written = 0;
    int retry_cnt = 0;

    while (written < buflen) {
        retval = recv(socket_fd, (char *)buf + written, buflen - written, flag);

        if (retval == -1) {
            return retval;
        }

        written += retval;

        if (written == buflen) {
            return (0);
        }

        retry_cnt += 1;
        printf("retry recv...[%d]\n", retry_cnt);
    }

    return (0);
}

static int proc_server(void)
{
    int retval;
    int socket_fd;
    int peer_fd;
    struct sockaddr_un addr;
    char buf[1024];
    

    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        perror("socket()");

        return (-1);
    }

    memset(&addr, 0x00, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PAHT, sizeof(addr.sun_path) - 1);

    if (bind(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind()");
        close(socket_fd);

        return (-1);
    }

    listen(socket_fd, 5);

    peer_fd = accept(socket_fd, NULL, NULL);

    if (peer_fd < 0) {
        perror("accept()");
        close(socket_fd);

        return (-1);
    }

    memset(buf, 0x00, sizeof(buf));

#if 0
    retval = recv(peer_fd, buf, sizeof(buf), 0);
#else
    retval = stream_recv(peer_fd, buf, sizeof(buf), 0);
#endif

    if (retval == -1) {
        perror("recv()");
        close(socket_fd);

        return (-1);
    }

    printf("FROM CLIENT[%s]\n", buf);

    close(peer_fd);
    close(socket_fd);

    return (0);
}

int stream_send(int socket_fd, void *buf, size_t buflen, int flag)
{
    int retval;
    int written = 0;
    int retry_cnt = 0;

    while (written < buflen) {
        retval = send(socket_fd, (char *)buf + written, buflen - written, flag);

        if (retval == -1) {
            return retval;
        }

        written += retval;

        if (written == buflen) {
            return (0);
        }

        retry_cnt += 1;
        printf("retry send...[%d]\n", retry_cnt);
    }

    return (0);
}

static int proc_client(void)
{
    int retval;
    int socket_fd;
    struct sockaddr_un addr;
    char buf[1024];

    socket_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        perror("socket()");

        return (-1);
    }

    memset(&addr, 0x00, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PAHT, sizeof(addr.sun_path) - 1);

    if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect()");
        close(socket_fd);

        return (-1);
    }

    memset(buf, 0x00, sizeof(buf));

    snprintf(buf, sizeof(buf), "HELLO THERE");

#if 0
    retval = send(socket_fd, buf, sizeof(buf), 0);
#else
    retval = stream_send(socket_fd, buf, sizeof(buf), 0);
#endif

    if (retval == -1) {
        perror("send()");
        close(socket_fd);

        return (-1);
    }

    close(socket_fd);

    return (0);
}

int main(int argc, char **argv)
{
    int retval;

    if (argc < 2) {
        usage(argv[0]);

        return (-1);
    }

    if (!strcmp(argv[1], "server")) {
        retval = proc_server();

        if (retval == -1) {
            return (-1);
        }
    }
    else if (!strcmp(argv[1], "client")) {
        retval = proc_client();

        if (retval == -1) {
            return (-1);
        }
    }
    else {
        usage(argv[0]);

        return (-1);
    }

    return (0);
}