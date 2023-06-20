#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int fd, n;
    char buf[10];

    fd = open("jo.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    n = read(fd, buf, 5);

    if (n == -1) {
        perror("read");
        exit(1);
    }

    buf[n] = '\0';

    printf("n = %d, buf = %s\n", n, buf);

    close(fd);
}