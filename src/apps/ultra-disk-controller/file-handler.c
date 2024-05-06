#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#include "file-handler.h"

FILE        *file_listp;
int     udc_file_idx = 0;


int jfinder(char *path, char *ext, udc_file *udc_file_list)
{
    char        list_path[FILENAME_MAX];

    memset(list_path, 0x00, sizeof(list_path));

    strcpy(list_path, "./tmp/file_list.txt");

    if ((file_listp = fopen(list_path, "w+")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");

        return (-1);
    }
    else {
        ultra_finder(path, ext, udc_file_list);
    }

    fclose(file_listp);

    return (1);
}

int ultra_finder(char *path, char *ext, udc_file *udc_file_list)
{
    DIR             *dd = NULL;
    struct dirent   *entry = NULL;
    struct stat     buff;
    char            file_ext[16];
    char            *pos;
    char            sub_path[1024];
    udc_file        fudc_file;

    memset(file_ext, 0x00, sizeof(file_ext));
    memset(sub_path, 0x00, sizeof(sub_path));

    if ((dd = opendir(path)) == NULL) {
        printf("%s 를 열수 없습니다.\n", path);

        return (-1);
    }

    while ((entry = readdir(dd)) != NULL) {
        lstat(entry->d_name, &buff);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            sprintf(sub_path, "%s/%s", path, entry->d_name);
            printf("[디렉토리이름] %s\n", entry->d_name);

            ultra_finder(sub_path, ext, udc_file_list);
        }
        else if (entry->d_type == DT_REG) {
            printf("[파일이름] %s\n", entry->d_name);

            pos = strchr(entry->d_name, '.');
            strcpy(file_ext, pos + 1);

            if (strcmp(file_ext, ext) == 0) {
                printf("[확장자] %s\n", file_ext);

                sprintf(udc_file_list[udc_file_idx].path, "%s/", path);
                strcpy(udc_file_list[udc_file_idx].file_name, entry->d_name);
                strcpy(udc_file_list[udc_file_idx].ext, file_ext);
                udc_file_list[udc_file_idx].type = VALID_FILE;

                sprintf(fudc_file.path, "%s/", path);
                strcpy(fudc_file.file_name, entry->d_name);
                strcpy(fudc_file.ext, file_ext);
                fudc_file.type = VALID_FILE;

                fwrite(fudc_file, sizeof(udc_file), 1, file_listp);

                udc_file_idx += 1;
            }
        }
    }

	closedir(dd);

    udc_file_idx = 0;

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
