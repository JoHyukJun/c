/*
    - 다음은 아래와 같이 정의된 XYZ 형을 요소형으로 하는 요소 개수 10인 배열을, 스트림 fp 와 연결된 바이너리 파일로 쓰는 프로그램 일부와 읽는 프로그램 일부다.
*/


#include <stdio.h>


typedef struct {
    int x;
    int y;
    double z;
} XYZ;


int main(void) {
    XYZ a[10];
    FILE *fp;
    char name[FILENAME_MAX];

    printf("파일 이름: ");
    scanf("%s", name);

    if ((fp = fopen(name, "rb")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fwrite(&a, sizeof(XYZ), 10, fp);
        fread(a, sizeof(XYZ), 10, fp);

        fclose(fp);
    }
    

    return 0;
}