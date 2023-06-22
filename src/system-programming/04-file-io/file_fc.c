#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *rfp, *wfp;
    int c;

    if ((rfp = fopen("jo.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if ((wfp = fopen("jo.bak", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((c = fgetc(rfp)) != EOF) {
        fputc(c, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}