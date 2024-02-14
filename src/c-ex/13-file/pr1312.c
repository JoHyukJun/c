/*
    - 다음은 스트림 fp 와 연결된 바이너리 파일에 대해 변수 x 와 배열 a 의 모든 요소를 읽는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    FILE *fp;
    int x;
    int a[10];
    char name[FILENAME_MAX];

    printf("파일 이름: ");
    scanf("%s", name);

    if ((fp = fopen(name, "rb")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fread(&x, sizeof(int), 1, fp);
        fread(a, sizeof(int), 10, fp);

        fclose(fp);
    }

    return 0;
}