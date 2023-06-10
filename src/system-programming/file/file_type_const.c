#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    stat("jo.txt", &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
    
    kind = statbuf.st_mode & S_IFMT;
    
    printf("kind = %o\n", kind);

    switch (kind)
    {
    case S_IFBLK:
        printf("jo.txt: symbolic link\n");
        break;
    case S_IFDIR:
        printf("jo.txt: directory\n");
        break;
    case S_IFREG:
        printf("jo.txt: regular file\n");
        break;
    }
}