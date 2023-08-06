#include <errno.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    int perm;

    if (access("jo.txt", F_OK) == -1 && errno == ENOENT)
         printf("jo.txt: file not exist\n");

    perm = access("jo.txt", R_OK);

    if (perm == 0)
        printf("jo.txt: read permmission is permmitted\n");
    else if (perm == -1 && errno == EACCES)
        printf("jo.txt: read permmission is not permmitted\n");
}