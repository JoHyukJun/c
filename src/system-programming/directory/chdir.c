#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    char *cwd;

    cwd = getcwd(NULL, BUFSIZ);
    printf("1. CUR DIR: %s\n", cwd);

    chdir("jo");

    cwd = getcwd(NULL, BUFSIZ);
    printf("2. CUR DIR: %s\n", cwd);

    free(cwd);
}