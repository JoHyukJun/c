#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    char *cur;

    char *next_dir;

    if (argc == 1) {
        printf("input file name\n");

        return 0;
    }

    next_dir = argv[1];

    cur = getcwd(NULL, BUFSIZ);
    printf("1. DIR: %s\n", cur);

    if (mkdir(next_dir) == -1) {
        perror("dir1");

        exit(1);
    }

    chdir(next_dir);

    cur = getcwd(NULL, BUFSIZ);
    printf("2. DIR: %s\n", cur);

    free(cur);
    free(next_dir);
}