#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    FILE *rfp, *wfp;
    int n;
    char buf[BUFSIZ];
    char *file_name;
    char *output_file_name;

    file_name = argv[1];
    output_file_name = argv[2];

    if ((rfp = fopen(file_name, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if ((wfp = fopen(output_file_name, "a")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while(n = fread(buf, sizeof(char), 2, rfp) > 0) {
        fwrite(buf, sizeof(char), 1, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}