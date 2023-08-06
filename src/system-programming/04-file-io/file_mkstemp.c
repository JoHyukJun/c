#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *fp;
    int fd;
    char template[32];
    int retval;

    fp = tmpfile();
    fputs("temp file", fp);
    fclose(fp);

    strcpy(template, "/tmp/joXXXXX");
    fd = mkstemp(template);
    write(fd, "temp file", 10);
    close(fd);
}