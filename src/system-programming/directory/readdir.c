#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main() {
    DIR *dp;
    struct dirent *dent;

    dp = opendir(".");

    while ((dent = readdir(dp))) {
        printf("name: %s  ", dent->d_name);
        printf("inode: %d\n", (int)dent->d_ino);
    }
    
    closedir(dp);
}