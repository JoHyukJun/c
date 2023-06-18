#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("input file name\n");

        return 0;
    }

    char buf[BUFSIZ];
    int n;

    char *file_name;
    int file_len = 0;
    char symlink_file[1024];

    file_name = argv[1];
    file_len = strlen(file_name);

    for (int i = 0; i < file_len; i++) {
        if (file_name[i] == '.') {
            symlink_file[i] = '.';
            symlink_file[i + 1] = 's';
            symlink_file[i + 2] = 'y';
            symlink_file[i + 3] = 'm';
            symlink_file[i + 4] = '\0';

            break;
        }
        else {
            symlink_file[i] = file_name[i];
        }
    }

    symlink(file_name, symlink_file);

    n = readlink(symlink_file, buf, BUFSIZ);

    if (n == -1) {
        perror("readlink");
        exit(1);
    }

    buf[n] = '\0';
    printf("READLINK = %s\n", buf);

    realpath(symlink_file, buf);
    printf("REALPATH = %s\n", buf);
}