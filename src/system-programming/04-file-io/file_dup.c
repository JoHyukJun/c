#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    int fd, fdd;

    fd = open("jo-2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        perror("create");
        exit(1);
    }

    close(1);

    fdd = dup(fd);
    
    printf("dup fd = %d\n", fdd);

    close(fd);
}