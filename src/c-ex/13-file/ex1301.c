#include <stdio.h>


int fexist(const char *filename) {
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        return 0;
    }

    fclose(fp);

    return 1;
}

int main(void) {
    FILE *fp;
    char fname[256];

    printf("파일 이름: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if (fp == NULL) {
        printf("이 파일은 없습니다.\n");
    }
    else {
        printf("이 파일은 있습니다.\n");
        fclose(fp);
    }

    if (fexist(fname)) {
        printf("이 파일은 없습니다.\n");
    }
    else {
        printf("이 파일은 있습니다.\n");
    }

    return 0;
}