#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("input auth\n");

        return 0;
    }
    else if (argc == 2) {
        printf("input file name\n");

        return 0;
    }

    char *auth;
    int auth_len = 0;
    char *file_name;

    auth = argv[1];
    auth_len = strlen(auth);
    file_name = argv[2];

    struct stat statbuf;

    stat(file_name, &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);

    if (auth_len < 3) {
        printf("input auth correct\n");

        return 0;
    }

    char accesser;
    accesser = auth[0];

    char appender;
    appender = auth[1];

    switch (accesser)
    {
    case 'u':
        if (appender == '+') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IRUSR);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWUSR);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXUSR);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '-') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IRUSR);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWUSR);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXUSR);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '=') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                }
                else if (auth[i] == 'w') {
                }
                else if (auth[i] == 'x') {
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else {
            printf("invalid access\n");
        }
        break;
    case 'g':
        if (appender == '+') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IRGRP);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWGRP);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXGRP);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '-') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IRGRP);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWGRP);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXGRP);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '=') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                }
                else if (auth[i] == 'w') {
                }
                else if (auth[i] == 'x') {
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else {
            printf("invalid access\n");
        }
        break;
    case 'o':
        if (appender == '+') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IROTH);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWOTH);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXOTH);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '-') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                    statbuf.st_mode &= ~(S_IROTH);
                }
                else if (auth[i] == 'w') {
                    statbuf.st_mode &= ~(S_IWOTH);
                }
                else if (auth[i] == 'x') {
                    statbuf.st_mode &= ~(S_IXOTH);
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else if (appender == '=') {
            for (int i = 2; i < auth_len; i++) {
                if (auth[i] == 'r') {
                }
                else if (auth[i] == 'w') {
                }
                else if (auth[i] == 'x') {
                }
                else {
                    printf("invalid access\n");
                }
            }
        }
        else {
            printf("invalid access\n");
        }
        break;
    default:
        printf("invalid access\n");
        break;
    }

    stat(file_name, &statbuf);

    printf("mode = %o\n", (unsigned int)statbuf.st_mode);
}