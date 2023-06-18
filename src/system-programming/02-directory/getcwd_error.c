#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    char *cwd;

    cwd = getcwd(NULL, BUFSIZ);

    if (cwd == NULL) {
        perror("getcwd");
        exit(1);
    }

    printf("1. CUR DIR: %s\n", cwd);
    free(cwd);

    chdir("jo");

    cwd = getcwd(NULL, BUFSIZ);
    printf("2. CUR DIR: %s\n", cwd);

    if (cwd == NULL) {
        perror("getcwd");
        exit(1);
    }

    free(cwd);
}
