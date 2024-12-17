#include "netlib.h"


int print_netlib()
{
    printf("NETLIB\n");

    return 0;
}

int tcp_open()
{
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        perror("socket()");

        return (-1);
    }

    return (sockfd);
}

int tcp_connect(sockfd, addr, port)
int sockfd;
char *addr;
int port;
{
    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect()");

        return (-1);
    }

    return (0);
}

int tcp_send_size(sockfd, buf, size)
int sockfd;
char *buf;
int size;
{
    int sent_size;

    sent_size = send(sockfd, buf, size, 0);

    if (sent_size == -1)
    {
        perror("send()");

        return (-1);
    }

    return (sent_size);
}

int tcp_send(sockfd, buf)
int sockfd;
char *buf;
{
    int sent_size;

    sent_size = send(sockfd, buf, strlen(buf), 0);

    if (sent_size == -1)
    {
        perror("send()");

        return (-1);
    }

    return (sent_size);
}

int tcp_recv_size(sockfd, buf, size)
int sockfd;
char *buf;
int size;
{
    int recv_size;

    recv_size = recv(sockfd, buf, size, 0);

    if (recv_size == -1)
    {
        perror("recv()");

        return (-1);
    }

    return (recv_size);
}

int tcp_recv(sockfd, buf)
int sockfd;
char *buf;
{
    int recv_size;

    recv_size = recv(sockfd, buf, 1024, 0);

    if (recv_size == -1)
    {
        perror("recv()");

        return (-1);
    }

    return (recv_size);
}

int tcp_close(sockfd)
int sockfd;
{
    if (close(sockfd) == -1)
    {
        perror("close()");

        return (-1);
    }

    return (0);
}