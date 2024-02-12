#include <stdio.h>

#define BUF_SIZE 1024


int main(void) {
    int n;
    char buf[BUF_SIZE];
    FILE *sfp;
    FILE *dfp;
    char sname[FILENAME_MAX];
    char dname[FILENAME_MAX];

    printf("복사할 내용이 있는 파일 이름: "); scanf("%s", sname);
    printf("내용을 복사해 넣을 파일 이름: "); scanf("%s", dname);

    if ((sfp = fopen(sname, "rb")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");
    }
    else {
        if ((dfp = fopen(dname, "wb")) == NULL) {
            printf("\a내용을 복사해 넣을 파일을 열 수 없습니다.");
        }
        else {
            while (1) {
                if ((n = fread(buf, 1, BUF_SIZE, sfp)) != 0) {
                    fwrite(buf, 1, n, dfp);
                }

                if (n < BUF_SIZE) {
                    break;
                }
            }

            fclose(dfp);
        }

        fclose(sfp);
    }

    return 0;
}