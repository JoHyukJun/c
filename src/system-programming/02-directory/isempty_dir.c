#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main() {
    DIR *dp;
    struct dirent *dent;

    char *dir_name;
    int ckr = 0;

    dir_name = "jo";

    dp = opendir(dir_name);

    while ((dent = readdir(dp))) {
        printf("name: %s\n", dent->d_name);

        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            ckr += 1;
        }
        else {
            ckr = -1;
        }
    }
    
    closedir(dp);

    printf("ckr num : %d\n", ckr);

    if (ckr == 2) {
        printf("EMPTY DIR\n");
        if (rmdir(dir_name) == -1) {
        perror(dir_name);

        exit(1);
        }
    }
}