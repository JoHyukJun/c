#include <time.h>
#include <stdio.h>
#include <unistd.h>


char *date_format[] = {"%G %m %d %w %H %M %s", "%G", "%m", "%d", "%w", "%r"};

int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;
    struct tm *tm;
    time_t timep;

    time(&timep);
    printf("time(sec): %d\n", (int)timep);
    tm = localtime(&timep);

    while ((n = getopt(argc, argv, "aymdwh :?")) != -1) {
        char buf[257];

        switch (n)
        {
        case 'a':
            strftime(buf, sizeof(buf), date_format[0], tm);
            printf("%s\n", buf);
            break;
        case 'y':
            strftime(buf, sizeof(buf), date_format[1], tm);
            printf("%s\n", buf);
            break;
        case 'm':
            strftime(buf, sizeof(buf), date_format[2], tm);
            printf("%s\n", buf);
            break;
        case 'd':
            strftime(buf, sizeof(buf), date_format[3], tm);
            printf("%s\n", buf);
            break;
        case 'w':
            strftime(buf, sizeof(buf), date_format[4], tm);
            printf("%s\n", buf);
            break;
        case 'h':
            strftime(buf, sizeof(buf), date_format[5], tm);
            printf("%s\n", buf);
            break;
        default:
            break;
        }

        printf("next optind: %d\n", optind);
    }
}