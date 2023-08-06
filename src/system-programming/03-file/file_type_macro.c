#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    int kind;

    stat("jo.txt", &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
    
    kind = statbuf.st_mode & S_IFMT;
    
    if(S_ISBLK(statbuf.st_mode))
        printf("jo.txt: symbolic link\n");

    if(S_ISDIR(statbuf.st_mode))
        printf("jo.txt: directory\n");

    if(S_ISREG(statbuf.st_mode))
        printf("jo.txt: regular file\n");
}