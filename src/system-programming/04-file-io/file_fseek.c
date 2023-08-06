#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE *rfp;
    int n;
    long cur;
    char buf[BUFSIZ];

    if ((rfp = fopen("jo.txt", "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    cur = ftell(rfp);
    printf("offset cur = %d\n", (int)cur);

    n = fread(buf, sizeof(char), 5, rfp);
    buf[n] = '\0';
    printf("-- resd str = %s\n", buf);

    fseek(rfp, 1, SEEK_CUR);

    cur = ftell(rfp);
    printf("offset cur = %d\n", (int)cur);

    n = fread(buf, sizeof(char), 6, rfp);
    buf[n] = '\0';
    printf("-- resd str = %s\n", buf);

    fseek(rfp, 1, SEEK_CUR);

    cur = ftell(rfp);
    printf("offset cur = %d\n", (int)cur);

    n = fread(buf, sizeof(char), 11, rfp);
    buf[n] = '\0';
    printf("-- resd str = %s\n", buf);

    rewind(rfp);
    cur = ftell(rfp);
    printf("rewind offset cur = %d\n", (int)cur);

    fclose(rfp);
}