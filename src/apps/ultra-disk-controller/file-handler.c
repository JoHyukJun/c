#include <stdio.h>

#include "file-handler.h"


int jcopy(char *orgin_filename, char *destination_filename)
{
    int n;
    char buf[BUF_SIZE];
    FILE *sfp;
    FILE *dfp;

    if ((sfp = fopen(orgin_filename, "r")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");

        return (-1);
    }
    else {
        if ((dfp = fopen(destination_filename, "w")) == NULL) {
            printf("\a내용을 복사해 넣을 파일을 열 수 없습니다.");

            return (-1);
        }
        else {
            while (1) {
                if ((n = fread(buf, 1, BUF_SIZE, sfp)) != 0) {
                    fwrite(buf, 1, n, dfp);
                }

                if (n < BUF_SIZE) {
                    break;
                }
            }

            fclose(dfp);
        }

        fclose(sfp);
    }

    return (0);
}


int file_handler(void)
{
    printf("file_handler\n");

    return 0;
}

