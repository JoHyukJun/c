#include <stdio.h>


int main(void) {
    int ch;
    FILE *fp;
    char fname[FILENAME_MAX];
    int n_count = 0;

    printf("파일 이름: ");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r'")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '\n') {
                n_count++;
            }
        }

        fclose(fp);

        printf("이 파일은 %d줄입니다.\n", n_count);
    }

    return 0;
}