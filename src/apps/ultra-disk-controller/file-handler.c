#include <stdio.h>
#include <string.h>

#include "file-handler.h"


int get_file_size(FILE *fp)
{
    int     retval;
    char    unit_name[16];
    int     unit_basis = 1;

    fseek(fp, 0, SEEK_END);

    retval = ftell(fp);
    
    fseek(fp, 0, SEEK_SET);

    if (retval >= 1000000000) {
        unit_basis = 1000000000;
        strcpy(unit_name, "GB");
    }
    else if (retval < 1000000000 && retval >= 1000000) {
        unit_basis = 1000000;
        strcpy(unit_name, "MB");
    }
    else if (retval < 1000000 && retval >= 1000) {
        unit_basis = 1000;
        strcpy(unit_name, "KB");
    }
    else {
        strcpy(unit_name, "B");
    }

    printf("FILE SIZE: %d(%s)\n", retval / unit_basis, unit_name);

    return (retval);
}

int jcopy(char *orgin_filename, char *destination_filename)
{
    int n, file_size;
    char buf[BUF_SIZE];
    FILE *sfp;
    FILE *dfp;

    if ((sfp = fopen(orgin_filename, "r")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");

        return (-1);
    }
    else {
        file_size = get_file_size(sfp);

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

