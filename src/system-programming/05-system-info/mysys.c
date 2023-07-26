#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;

    if (argc != 2) {
        printf("You can select options\n");
        printf("-a\n");
        printf("-h\n");
        printf("-p\n");
        printf("-l\n");
        printf("-x\n");

        exit(1);
    }


    while ((n = getopt(argc, argv, "ahplx:")) != -1) {

        switch (n)
        {
        case 'a':
            printf("max host name: %ld\n", sysconf(_SC_HOST_NAME_MAX));
            printf("max process: %ld\n", sysconf(_SC_CHILD_MAX));
            printf("max login name: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
            printf("max open file: %ld\n", sysconf(_SC_OPEN_MAX));
            printf("posix version: %ld\n", sysconf(_SC_VERSION));
            
            break;
        case 'h':
            printf("max host name: %ld\n", sysconf(_SC_HOST_NAME_MAX));

            break;
        case 'p':
            printf("max process: %ld\n", sysconf(_SC_CHILD_MAX));

            break;
        case 'l':
            printf("max login name: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
            
            break;
        case 'x':
            printf("posix version: %ld\n", sysconf(_SC_VERSION));

            break;
        case '?':
            printf("You can select options\n");
            printf("-a\n");
            printf("-h\n");
            printf("-p\n");
            printf("-l\n");
            printf("-x\n");
            break;
        }
    }
}