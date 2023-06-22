#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *rfp, *wfp;
    char buf[BUFSIZ];

    if ((rfp = fopen("jo.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    if ((wfp = fopen("jo.bak", "w")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buf, BUFSIZ, rfp)) != EOF) {
        fputs(buf, wfp);
    }

    fclose(rfp);
    fclose(wfp);
}