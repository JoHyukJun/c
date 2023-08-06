#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    int n;
    extern char *optarg;
    extern int optind;

    struct stat statbuf;
    char acc[10];

    while ((n = getopt(argc, argv, "f:")) != -1) {
        switch (n)
        {
        case 'f':
            stat(optarg, &statbuf);

            if ((statbuf.st_mode & S_IREAD) != 0) {
                acc[0] = 'r';
            }
            else {
                acc[0] = '-';
            }

            if ((statbuf.st_mode & S_IWUSR) != 0) {
                acc[1] = 'w';
            }
            else {
                acc[1] = '-';
            }

            if ((statbuf.st_mode & S_IXUSR) != 0) {
                acc[2] = 'x';
            }
            else {
                acc[3] = '-';
            }

            if ((statbuf.st_mode & S_IRGRP) != 0) {
                acc[4] = 'r';
            }
            else {
                acc[4] = '-';
            }

            if ((statbuf.st_mode & S_IWGRP) != 0) {
                acc[5] = 'w';
            }
            else {
                acc[5] = '-';
            }

            if ((statbuf.st_mode & S_IXGRP) != 0) {
                acc[6] = 'x';
            }
            else {
                acc[6] = '-';
            }

            if ((statbuf.st_mode & S_IROTH) != 0) {
                acc[7] = 'r';
            }
            else {
                acc[7] = '-';
            }

            if ((statbuf.st_mode & S_IWOTH) != 0) {
                acc[8] = 'w';
            }
            else {
                acc[8] = '-';
            }

            if ((statbuf.st_mode & S_IXOTH) != 0) {
                acc[9] = 'x';
            }
            else {
                acc[9] = '-';
            }

            acc[10] = '\0';

            printf("%s %d %s\n", optarg, (int)statbuf.st_uid, acc);

            break;
        default:
            break;
        }
    }
}