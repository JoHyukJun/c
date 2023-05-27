#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main() {
    DIR *dp;
    struct  dirent *dent;
    
    long loc;

    dp = opendir(".");

    printf("start position : %ld\n", telldir(dp));
    while((dent = readdir(dp))) {
        printf("read : %s\n", dent->d_name);
    }

    printf("** move directory pointer **\n");
    readdir(dp);
    loc = 2;
    seekdir(dp, loc);
    printf("cur position file name : %s\n", readdir(dp)->d_name);

    closedir(dp);
}