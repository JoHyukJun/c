#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dent;

    char *dir_name;
    int flag = 0;

    dir_name = ".";

    if (argc == 1) {
        printf("input file name\n");

        return 0;
    }

    char *serach_name;
    serach_name = argv[1];

    printf("SERCHING FOR: %s\n", serach_name);

    dp = opendir(dir_name);

    while ((dent = readdir(dp))) {
        printf("name: %s\n", dent->d_name);

        if (strcmp(dent->d_name, serach_name) == 0) {
            flag = 1;
            break;
        }
    }

    printf("FLAG: %d\n", flag);

    if (flag == 1) {
        printf("YOUR FILE EXEIST\n");
    }

    free(dir_name);
    free(serach_name);

    closedir(dp);
}