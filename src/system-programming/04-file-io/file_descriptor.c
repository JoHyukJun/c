#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int fd;
    
    close(0);
    
    fd = open("jo.txt", O_RDWR);

    if (fd == -1) {
        perror("EXCL\n");
        exit(1);
    }

    printf("jo.txt: fd = %d\n", fd);
    close(fd);
}