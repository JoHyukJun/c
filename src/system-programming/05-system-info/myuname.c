#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;
    struct utsname uts;

    if (argc != 2) {
        printf("You can select options\n");
        printf("-a\n");
        printf("-k\n");
        printf("-r\n");
        printf("-n\n");
        printf("-h\n");
        printf("-s\n");

        exit(1);
    }


    while ((n = getopt(argc, argv, "akrnhs:")) != -1) {

        switch (n)
        {
        case 'a':
            if (uname(&uts) == -1) {
                perror("uname");
                exit(1);
            }

            printf("osname : %s\n", uts.sysname);
            printf("nodename : %s\n", uts.nodename);
            printf("release : %s\n", uts.release);
            printf("version : %s\n", uts.version);
            printf("machine : %s\n", uts.machine);

            break;
        case 'k':
            if (uname(&uts) == -1) {
                perror("unmae");
                exit(1);
            }

            printf("release : %s\n", uts.release);

            break;
        case 'r':
            if (uname(&uts) == -1) {
                perror("unmae");
                exit(1);
            }

            printf("version : %s\n", uts.version);

            break;
        case 'n':
            if (uname(&uts) == -1) {
                perror("unmae");
                exit(1);
            }

            printf("nodename : %s\n", uts.nodename);

            break;
        case 'h':
            if (uname(&uts) == -1) {
                perror("unmae");
                exit(1);
            }

            printf("machine : %s\n", uts.machine);

            break;
        case 's':
            if (uname(&uts) == -1) {
                perror("unmae");
                exit(1);
            }

            printf("osname : %s\n", uts.sysname);

            break;
        case '?':
            printf("You can select options\n");
            printf("-a\n");
            printf("-k\n");
            printf("-r\n");
            printf("-n\n");
            printf("-h\n");
            printf("-s\n");
            break;
        }
    }
}