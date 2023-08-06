#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int rfd, wfd, n;
    char buf[10];

    rfd = open("jo.txt", O_RDONLY);

    if (rfd == -1) {
        perror("open");
        exit(1);
    }

    wfd = open("jo.bak", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (wfd == -1) {
        perror("open");
        exit(1);
    }

    while(n = read(rfd, buf, 1) > 0) {
        if (write(wfd, buf, n) != n) {
            perror("write");
        }
    }

    if (n == -1) {
        perror("read");
        exit(1);
    }

    close(rfd);
    close(wfd);
}