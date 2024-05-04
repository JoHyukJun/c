#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include "file-handler.h"


int ultra_finder(char *path, char *ext, udc_file *udc_file_list)
{
    DIR             *dd = NULL;
    struct dirent   *entry = NULL;
    struct stat     buff;
    char            tmp_ext[128];
    char            *pos;
    int             udc_file_idx;

    memset(tmp_ext, 0x00, sizeof(tmp_ext));
    udc_file_idx = 0;

    if ((dd = opendir(path)) == NULL) {
        printf("%s 를 열수 없습니다.\n", path);

        return (-1);
    }

    while ((entry = readdir(dd)) != NULL) {
        lstat(entry->d_name, &buff);

        if (entry->d_type == DT_DIR) {
            printf("[디렉토리이름] %s\n", entry->d_name);
        }
        else if (entry->d_type == DT_REG) {
            printf("[파일이름] %s\n", entry->d_name);

            pos = strchr(entry->d_name, '.');
            strcpy(tmp_ext, pos + 1);

            if (strcmp(tmp_ext, ext) == 0) {
                printf("[확장자] %s\n", tmp_ext);

                sprintf(udc_file_list[udc_file_idx].path, "%s/%s", path, entry->d_name);
                udc_file_list[udc_file_idx].type = VALID_FILE;

                printf("파일위치: %s\n", udc_file_list[udc_file_idx].path);

                udc_file_idx += 1;
            }
        }
    }

	closedir(dd);

    return (1);
}


void loader(long file_size, long snd_file_size)
{
    int     percentage = 0;

    percentage = (double)snd_file_size / file_size * 100;

    if (percentage == 0) {
        printf("=>                                =\r");
    }
    else if (percentage > 0 && percentage < 10) {
        printf("=@@@>                             =\r");
    }
    else if (percentage >= 10 && percentage < 20) {
        printf("=@@@@@@>                          =\r");
    }
    else if (percentage >= 20 && percentage < 30) {
        printf("=@@@@@@@@@>                       =\r");
    }
    else if (percentage >= 30 && percentage < 40) {
        printf("=@@@@@@@@@@@@>                    =\r");
    }
    else if (percentage >= 40 && percentage < 50) {
        printf("=@@@@@@@@@@@@@@@>                 =\r");
    }
    else if (percentage >= 50 && percentage < 60) {
        printf("=@@@@@@@@@@@@@@@@@@>              =\r");
    }
    else if (percentage >= 60 && percentage < 70) {
        printf("=@@@@@@@@@@@@@@@@@@@@@>           =\r");
    }
    else if (percentage >= 70 && percentage < 80) {
        printf("=@@@@@@@@@@@@@@@@@@@@@@@@>        =\r");
    }
    else if (percentage >= 80 && percentage < 90) {
        printf("=@@@@@@@@@@@@@@@@@@@@@@@@@@@>     =\r");
    }
    else if (percentage >= 90 && percentage < 100) {
        printf("=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>  =\r");
    }
    else if (percentage == 100) {
        printf("===================================\n");
        printf("=    @@@    @ @   @@  @  @@@@     =\n");
        printf("=    @  @  @   @  @ @ @  @@@      =\n");
        printf("=    @@@    @ @   @  @@  @@@@     =\n");
        printf("===================================\n");
    }
}


long get_file_size(FILE *fp)
{
    long    retval;
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

    printf("FILE SIZE: %ld(%s)\n", retval / unit_basis, unit_name);

    return (retval);
}


int jcopy(char *orgin_filename, char *destination_filename)
{
    int     n;
    long    file_size, snd_file_size;
    char    buf[BUF_SIZE];
    FILE    *sfp;
    FILE    *dfp;

    if ((sfp = fopen(orgin_filename, "r")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");

        return (-1);
    }
    else {
        file_size = get_file_size(sfp);
        snd_file_size = 0;

        if ((dfp = fopen(destination_filename, "w")) == NULL) {
            printf("\a내용을 복사해 넣을 파일을 열 수 없습니다.");

            return (-1);
        }
        else {
            while (1) {
                if ((n = fread(buf, 1, BUF_SIZE, sfp)) != 0) {
                    fwrite(buf, 1, n, dfp);

                    snd_file_size += n;

                    loader(file_size, snd_file_size);
                }

                if (n < BUF_SIZE) {
                    break;
                }
            }

            fclose(dfp);
        }

        fclose(sfp);
    }

    return (1);
}


int file_handler(void)
{
    printf("file_handler\n");

    return 0;
}
