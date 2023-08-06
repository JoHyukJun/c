#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    FILE *rfp;
    int rfd;
    int id, s1, s2, s3, n;
    char *file_name;

    file_name = argv[1];

    if ((rfd = open(file_name, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    rfp = fdopen(rfd, "r");

    printf("학번    평균\n");

    while ((n = fscanf(rfp, "%d %d %d %d", &id, &s1, &s2, &s3)) != EOF) {
        printf("%d : %d\n", id, (s1+s2+s3)/3);
    }

    fclose(rfp);
}