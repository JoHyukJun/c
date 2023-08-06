#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int fd, n;
    off_t start, cur;
    char buf[256];

    fd = open("jo.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    start = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 255);
    buf[n] = '\0';

    printf("offset start = %d, n = %d, read str = %s", (int)start, n, buf);

    cur = lseek(fd, 0, SEEK_CUR);

    printf("offset cur = %d\n", (int)cur);

    start = lseek(fd, 6, SEEK_SET);
    n = read(fd, buf, 255);
    buf[n] = '\0';

    printf("offset start = %d, n = %d, read str = %s", (int)start, n, buf);

    close(fd);
}