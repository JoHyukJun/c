#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    int rfd, wfd, n, i;
    char buf[BUFSIZ];
    char *cwd;
    char full_dir[BUFSIZ];
    char *dir_name;
    char *file_name;

    dir_name = argv[1];
    file_name = argv[2];

    rfd = open(file_name, O_RDONLY);

    if (rfd == -1) {
        perror("open");
        exit(1);
    }

    if (mkdir(dir_name) == -1) {
        perror("mkdir");

        exit(1);
    }

    cwd = getcwd(NULL, BUFSIZ);

    sprintf(full_dir, "%s/%s/%s", cwd, dir_name, file_name);
    
    wfd = open(full_dir, O_CREAT | O_WRONLY | O_TRUNC, 0666);

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

    int ret;

    ret = remove(file_name);

    if (ret == -1) {
        perror("remove");
        exit(1);
    }

    printf("removed\n");

    close(rfd);
    close(wfd);
}