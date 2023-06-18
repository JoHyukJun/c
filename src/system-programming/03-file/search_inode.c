#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int main() {
    DIR *dp;
    struct dirent *dent;
    struct dirent *in_dent;

    dp = opendir(".");

    char *file_name;
    int inode = 0;
    long loc = 0; 

    while ((dent = readdir(dp))) {
        file_name = dent->d_name;
        inode = (int)dent->d_ino;

        printf("CUR FILE: %s\n", file_name);

        seekdir(dp, 0);
        
        while ((in_dent = readdir(dp)))
        {
            if (strcmp(file_name, in_dent->d_name)) {
                continue;
            }
            else {
                if (inode == (int)in_dent->d_ino) {
                    printf("SAME INODE FILE: %s\n", in_dent->d_name);
                }
            }
        }

        loc += 1;
        seekdir(dp, loc);
    }
    
    closedir(dp);
}