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

            stat(optarg, &statbuf);

            printf("file mode: %o\n", (unsigned int)statbuf.st_mode);

            break;
        default:
            break;
        }
    }
}