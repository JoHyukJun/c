#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    struct stat statbuf;

    stat("jo.txt", &statbuf);

    printf("link cnt = %d\n", (int)statbuf.st_nlink);

    link("jo.txt", "jo.ln");
    
    stat("jo.txt", &statbuf);

    printf("link cnt = %d\n", (int)statbuf.st_nlink);
}