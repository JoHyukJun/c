/*
    - 다음은 스트림 fp 와 연결된 텍스트 파일에 대해 변수 x 와 배열 a 의 모든 요소를 1줄에 1개씩 쓰는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    FILE *fp;
    int x;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    char name[FILENAME_MAX];

    printf("파일 이름: ");
    scanf("%s", name);

    if ((fp = fopen(name, "w")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fprintf(fp, "%d\n", x);

        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
            fprintf(fp, "%d\n", a[i]);
        }

        fclose(fp);
    }

    return 0;
}