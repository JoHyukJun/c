#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main() {
    DIR *dp;
    struct dirent *dent;

    char *dir_name;

    dir_name = ".";

    dp = opendir(dir_name);

    while ((dent = readdir(dp))) {
        if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0) {
            continue;
        }
        else {
            printf("name: %s\n", dent->d_name);
        }
    }
    
    closedir(dp);
}