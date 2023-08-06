#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int fd, n, i;
    char buf[BUFSIZ];
    char *file_name;

    file_name = argv[1];

    fd = open(file_name, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    n = read(fd, buf, BUFSIZ);

    if (n == -1) {
        perror("read");
        exit(1);
    }

    buf[n] = '\0';

    int row;
    char *line;

    row = 0;
    line = strtok(buf, "\n");

    while(line) {
        printf("%d   %s\n", row, line);
        row += 1;

        line = strtok(NULL, "\n");
    }
    
    close(fd);
}