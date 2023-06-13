#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main() {
    DIR *dp;
    struct dirent *dent;

    dp = opendir(".");

    struct stat statbuf;

    while ((dent = readdir(dp))) {
        if (strcmp(dent->d_name, ".") == 0 | strcmp(dent->d_name, "..") == 0)
            continue;
        
        stat(dent->d_name, &statbuf);

        if (S_ISDIR(statbuf.st_mode))
            printf("dir name: %s\n", dent->d_name);
    }
    
    closedir(dp);
}