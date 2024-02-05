#include <stdio.h>


int main(void) {
    int i, ch;
    FILE *fp;
    char fname[FILENAME_MAX];
    int cnt[10] = {0};

    printf("파일 이름: ");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r'")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch >= '0' && ch <= '9') {
                cnt[cn - '0']++;
            }
        }

        fclose(fp);

        puts("숫자 문자의 출현 횟수");
        
        for (i = 0; i < 10; i++) {
            printf("%d: %d\n", i, cnt[i]);
        }
    }

    return 0;
}