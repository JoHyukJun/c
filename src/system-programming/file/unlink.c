#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    struct stat statbuf;
    
    stat("jo.ln", &statbuf);
    printf("jo.ln : link cnt = %d\n", (int)statbuf.st_nlink);

    unlink("jo.ln");

    stat("jo.ln", &statbuf);
    printf("jo.ln : link cnt = %d\n", (int)statbuf.st_nlink);
}