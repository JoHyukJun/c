/*
    - 다음은 스트림 fp 와 연결된 텍스트 파일에서 1줄에 1개씩 10진수로 저장된 변수 x 와 배열 a 의 모든 요소를 읽는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    FILE *fp;
    int x;
    int a[10];
    int i;
    char name[FILENAME_MAX];

    printf("파일 이름: ");
    scanf("%s", name);

    if ((fp = fopen(name, "r")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fscanf(fp, "%d", &x);
        printf("%d\n", x);

        for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
            fscanf(fp, "%d", &a[i]);
            printf("%d\n", a[i]);
        }

        fclose(fp);
    }

    return 0;
}