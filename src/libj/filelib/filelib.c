#include "filelib.h"


int print_filelib()
{
    printf("FILELIB\n");

    return 0;
}

int fexist(filename) 
const char *filename;
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fclose(fp);

    return (1);
}

int ferase(filename)
const char *filename
{
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    fclose(fp);

    return (1);
}

int fcopy(src_filename, dst_filename)
const char *src_filename;
const char *dst_filename;
{
    FILE *sfp, *dfp;
    int ch;

    if ((sfp = fopen(src_filename, "rb")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    if ((dfp = fopen(dst_filename, "wb")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    while ((ch = fgetc(sfp)) != EOF) {
        fputc(ch, dfp);
    }

    fclose(dfp);
    fclose(sfp);

    return (1);
}