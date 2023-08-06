#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    chmod("jo.txt", S_IRWXG | S_IRGRP | S_IXGRP | S_IROTH);

    stat("jo.txt", &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);

    statbuf.st_mode |= S_IWGRP;
    statbuf.st_mode &= ~(S_IROTH);

    chmod("jo.txt", statbuf.st_mode);
    
    stat("jo.txt", &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
}