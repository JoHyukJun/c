#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *rfp;
    char buf[BUFSIZ];
    int c;

    if ((rfp = fopen("jo.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    while ((c = fread(buf, sizeof(char)*2, 4, rfp)) > 0) {
        buf[8] = '\0';
        printf("c = %d, buf = %s\n", n, buf);
    }

    fclose(rfp);
}