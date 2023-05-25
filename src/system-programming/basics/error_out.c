#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

extern int errno;


int main() {
    char *err;

    if(access("test.txt", F_OK) == -1) {
        err = strerror(errno);
        
        printf("errno=%d\n", errno);
        printf("err: %s(test.txt)\n", err);
    }
}