#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    FILE *rfp;
    int n;
    char buf[BUFSIZ];
    char *file_name;

    file_name = argv[1];

    if ((rfp = fopen(file_name, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while(n = fread(buf, sizeof(char), 1, rfp) > 0) {
        printf("%s", buf);
        fseek(rfp, 1, SEEK_CUR);
    }

    fclose(rfp);
}