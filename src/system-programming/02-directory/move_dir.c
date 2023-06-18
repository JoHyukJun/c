#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


int main() {
    char *cur;
    char *move;

    cur = getcwd(NULL, BUFSIZ);
    printf("1. DIR: %s\n", cur);

    chdir("jo");

    move = getcwd(NULL, BUFSIZ);
    printf("2. DIR: %s\n", move);

    if (mkdir("dir1") == -1) {
        perror("dir1");

        exit(1);
    }

    chdir(cur);

    move = getcwd(NULL, BUFSIZ);
    printf("3. DIR: %s\n", move);

    free(cur);
    free(move);
}