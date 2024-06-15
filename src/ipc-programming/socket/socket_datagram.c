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

static int proc_server(void)
{
    int retval;
    int socket_fd;
    struct sockaddr_un addr;
    char buf[1024];
    

    socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);

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

    memset(buf, 0x00, sizeof(buf));

    retval = recvfrom(socket_fd, buf, sizeof(buf), 0, NULL, NULL);

    if (retval == -1) {
        perror("recvfrom()");
        close(socket_fd);

        return (-1);
    }

    printf("FROM CLIENT[%s]\n", buf);

    close(socket_fd);

    return (0);
}

static int proc_client(void)
{
    int retval;
    int socket_fd;
    struct sockaddr_un addr;
    char buf[1024];

    socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);

    if (socket_fd == -1) {
        perror("socket()");

        return (-1);
    }

    memset(&addr, 0x00, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PAHT, sizeof(addr.sun_path) - 1);

    memset(buf, 0x00, sizeof(buf));

    snprintf(buf, sizeof(buf), "HELLO THERE");

    retval = sendto(socket_fd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));

    if (retval == -1) {
        perror("sendto()");
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