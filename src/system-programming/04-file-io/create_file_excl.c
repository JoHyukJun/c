#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd;
    mode_t mode;

    mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    fd = open("jo.txt", O_CREAT | O_EXCL, mode);

    if (fd == -1) {
        perror("EXCL\n");
        exit(1);
    }

    close(fd);
}