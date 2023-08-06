#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    stat("jo.txt", &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
    
    if((statbuf.st_mode & S_IREAD) != 0)
        printf("jo.txt: user has a read permission\n");

    if((statbuf.st_mode & (S_IREAD >> 3)) != 0)
        printf("jo.txt: group has a read permission\n");

    if((statbuf.st_mode & S_IROTH) != 0)
        printf("jo.txt: other have a read permission\n");
}