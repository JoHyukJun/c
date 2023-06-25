#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *rfp, *wfp;
    char buf[BUFSIZ];
    int c;

    if ((rfp = fopen("jo.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if ((wfp = fopen("jo.bak", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((c = fread(buf, sizeof(char)*2, 4, rfp)) > 0) {
        fwrite(buf, sizeof(char)*2, c, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}