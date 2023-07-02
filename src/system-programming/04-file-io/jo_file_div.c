#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int rfd, n;
    char buf[BUFSIZ];

    rfd = open("jo.txt", O_RDONLY);

    if (rfd == -1) {
        perror("open");
        exit(1);
    }

    while(n = read(rfd, buf, 3) > 0) {
        printf("%s", buf);
        printf(" ");
    }

    if (n == -1) {
        perror("read");
        exit(1);
    }

    close(rfd);
}