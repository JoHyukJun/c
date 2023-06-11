#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    char buf[BUFSIZ];
    
    realpath("jo.sym", buf);
    printf("jo.sym: REALPATH = %s\n", buf);
}