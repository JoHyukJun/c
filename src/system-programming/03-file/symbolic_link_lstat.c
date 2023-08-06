#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    stat("jo.txt", &statbuf);

    printf("link cnt = %d\n", (int)statbuf.st_nlink);
    printf("inode = %d\n", (int)statbuf.st_ino);
    
    stat("jo.sym", &statbuf);
    printf("link cnt = %d\n", (int)statbuf.st_nlink);
    printf("inode = %d\n", (int)statbuf.st_ino);

    lstat("jo.sym", &statbuf);
    printf("link cnt = %d\n", (int)statbuf.st_nlink);
    printf("inode = %d\n", (int)statbuf.st_ino);
}