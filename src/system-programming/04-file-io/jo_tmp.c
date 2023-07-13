#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *rfp, *tfp;
    int rfd;
    int id, s1, s2, s3, n;
    char *file_name;
    char *tmp_file;
    char *buf;
    char template[32];

    file_name = argv[1];

    tfp = tmpfile();

    strcpy(template, "/tmp/johj-XXXXXX");
    mkstemp(template);

    printf("tmp file name: %s\n", template);

    if ((rfd = open(file_name, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    rfp = fdopen(rfd, "r");

    fprintf(tfp, "학번    평균\n");

    while ((n = fscanf(rfp, "%d %d %d %d", &id, &s1, &s2, &s3)) != EOF) {
        fprintf(tfp, "%d : %d\n", id, (s1+s2+s3)/3);
    }

    fclose(rfp);
    fclose(tfp);
}