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

int funlink(filename)
const char *filename;
{
    if (unlink(filename) == -1) {
        perror("unlink()");

        return (-1);
    }

    return (1);
}

int fcopy(src_filename, dst_filename)
const char *src_filename;
const char *dst_filename;
{
    FILE *sfp, *dfp;
    int ch;
    long src_size, copied_size = 0;

    if ((sfp = fopen(src_filename, "rb")) == NULL) {
        perror("fopen()");

        return (-1);
    }

    if ((dfp = fopen(dst_filename, "wb")) == NULL) {
        perror("fopen()");
        fclose(sfp);

        return (-1);
    }

    // Get the size of the source file
    fseek(sfp, 0, SEEK_END);
    src_size = ftell(sfp);
    fseek(sfp, 0, SEEK_SET);

    while ((ch = fgetc(sfp)) != EOF) {
        fputc(ch, dfp);
        copied_size++;

        // Display progress bar
        int progress = (int)((copied_size / (double)src_size) * 100);
        printf("\rProgress: %d%%", progress);
        fflush(stdout);
    }

    printf("\n");

    fclose(dfp);
    fclose(sfp);

    return (1);
}