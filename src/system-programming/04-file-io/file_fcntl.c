#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int fd, flag;

    fd = open("jo.txt", O_RDONLY);

    if (fd == -1) {
        perror("create");
        exit(1);
    }

    if ((flag = fcntl(fd, F_GETFL)) == -1) {
        perror("fcntl");
        exit(1);
    }

    flag |= O_APPEND;

    if (fcntl(fd, F_SETFL, flag) == -1) {
        perror("fcntl");
        exit(1);
    }

    if (write(fd, "test test\n", 15) != 15) {
        perror("write");
    }

    close(fd);
}