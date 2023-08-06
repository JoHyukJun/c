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
        printf("read : %s -> ", dent->d_name);
        printf("cur position : %ld\n", telldir(dp));
    }

    printf("** directory position rewind **\n");
    rewinddir(dp);
    printf("cur position : %ld\n", telldir(dp));

    printf("** move directory pointer **\n");
    readdir(dp);
    loc = telldir(dp);
    seekdir(dp, loc);
    printf("cur position : %ld\n", telldir(dp));

    dent = readdir(dp);
    
    printf("read : %s\n", dent->d_name);

    closedir(dp);
}