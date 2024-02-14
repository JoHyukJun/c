/*
    - 다음은 텍스트 파일을 복사하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int ch;
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
            while ((ch = fgetc(sfp)) != EOF) {
                fputc(ch, dfp);
            }

            fclose(dfp);
        }

        fclose(sfp);
    }

    return 0;
}