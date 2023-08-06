#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *fp;
    int fd, n;
    char str[BUFSIZ];

    fp = fopen("jo.txt", "r");

    if (fp == -1) {
        perror("fopen");
        exit(1);
    }

    fd = fileno(fp);

    n = read(fd, str, BUFSIZ);
    str[n] = '\0';
    printf("read: %s\n", str);

    close(fd);
}