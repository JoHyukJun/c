#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;

    while ((n = getopt(argc, argv, "f:")) != -1) {
        switch (n)
        {
        case 'f':
            printf("file name: %s\n", optarg);

            struct stat statbuf;
            int kind;

            stat(optarg, &statbuf);

            kind = statbuf.st_mode & S_IFMT;
    
            if(S_ISBLK(statbuf.st_mode))
                printf("%s: symbolic link\n", optarg);

            if(S_ISDIR(statbuf.st_mode))
                printf("%s: directory\n", optarg);

            if(S_ISREG(statbuf.st_mode))
                printf("%s: regular file\n", optarg);

            break;
        default:
            break;
        }
    }
}