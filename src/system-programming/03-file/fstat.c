#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int fd;
    struct stat statbuf;

    fd = open("jo.txt", O_RDONLY);

    if (fd == -1) {
        perror("open: jo.txt");
        exit(1);
    }

    fstat(fd, &statbuf);

    printf("indoe = %d\n", (int)statbuf.st_ino);
    printf("UID = %d\n", (int)statbuf.st_uid);

    close(fd);
}