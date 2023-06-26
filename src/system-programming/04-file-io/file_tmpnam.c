#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char *fname;
    char *ffname;
    char fntmp[BUFSIZ];
    char template[32];

    fname = tmpnam(NULL);
    printf("tmp file name: %s\n", fname);

    fname = tmpnam("jo");
    printf("tmp file name: %s\n", fname);

    strcpy(template, "/tmp/joXXXXX");
    fname = mktemp(template);
    printf("tmp file name: %s\n", fname);
}