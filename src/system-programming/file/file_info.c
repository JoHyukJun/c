#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;

    struct stat statbuf;
    int kind;

    while ((n = getopt(argc, argv, "f:")) != -1) {
        switch (n)
        {
        case 'f':
            stat(optarg, &statbuf);

            printf("file name: %s\n", optarg);
            printf("inode num: %d\n", (int)statbuf.st_ino);
            printf("file type: ");

            kind = statbuf.st_mode & S_IFMT;
    
            if(S_ISBLK(statbuf.st_mode))
                printf("%s: symbolic link\n", optarg);

            if(S_ISDIR(statbuf.st_mode))
                printf("%s: directory\n", optarg);

            if(S_ISREG(statbuf.st_mode))
                printf("%s: regular file\n", optarg);

            printf("access type: %o\n", (unsigned int)statbuf.st_mode);
            printf("uid: %d\n", (int)statbuf.st_uid);

            break;
        default:
            break;
        }
    }
}