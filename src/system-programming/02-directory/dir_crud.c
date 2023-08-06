#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>


int main() {
    if (mkdir("dir1") == -1) {
        perror("dir1");

        exit(1);
    }

    if (mkdir("dir2") == -1) {
        perror("dir2");

        exit(1);
    }

    if (rmdir("dir1") == -1) {
        perror("dir1");

        exit(1);
    }

    if (rename("dir2", "hanbit") == -1) {
        perror("rename err");
        exit(1);
    }
}