/*
    - 다음은 스트림 fp 와 연결된 바이너리 파일에 대해 변수 x 와 배열 a 의 모든 요소를 쓰는 프로그램의 일부다.
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

    if ((fp = fopen(name, "wb")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fwrite(&x, sizeof(int), 1, fp);
        fwrite(a, sizeof(int), 10, fp);

        fclose(fp);
    }

    return 0;
}