#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("input auth\n");

        return 0;
    }
    else if (argc == 2) {
        printf("input file name\n");

        return 0;
    }

    char *auth;
    int auth_len = 0;
    char *file_name;

    auth = argv[1];
    auth_len = strlen(auth);
    file_name = argv[2];

    struct stat statbuf;

    stat(file_name, &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);

    if (auth_len < 3) {
        printf("input auth correct\n");

        return 0;
    }

    chmod(file_name, atoi(auth));

    stat(file_name, &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
}