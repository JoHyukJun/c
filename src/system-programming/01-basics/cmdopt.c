#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;

    if (argc == 1) {
        printf("You can select options\n");
        printf("-p\n");
        printf("-n\n");
        printf("-h\n");

        return 0;
    }

    while ((n = getopt(argc, argv, "pnh:")) != -1) {

        switch (n)
        {
        case 'p':
            printf("Welcome Linux System Programming!\n");
            break;
        case 'n':
            printf("Nice to meet\n");
            break;
        case 'h':
            printf("You can select options\n");
            printf("-p\n");
            printf("-n\n");
            printf("-h\n");
            break;
        case '?':
            printf("You can select options\n");
            printf("-p\n");
            printf("-n\n");
            printf("-h\n");
            break;
        }
    }
}