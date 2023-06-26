#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *fp;
    int fd;
    char str[BUFSIZ];

    fd = open("jo.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fp = fdopen(fd, "r");

    fgets(str, BUFSIZ, fp);

    printf("read: %s\n", str);

    fclose(fp);
}