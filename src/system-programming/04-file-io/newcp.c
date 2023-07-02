#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int rfd, wfd, n, i;
    char buf[BUFSIZ];
    char *file_name;
    char *cp_file_name;

    file_name = argv[1];
    cp_file_name = argv[2];

    rfd = open(file_name, O_RDONLY);

    if (rfd == -1) {
        perror("open");
        exit(1);
    }

    wfd = open(cp_file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

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