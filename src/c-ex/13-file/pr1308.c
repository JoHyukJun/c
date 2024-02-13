/*
    - 다음은 키보드로 읽어 들인 이름을 가진 텍스트 파일 내용을 화면에 출력하는 프로그램이다.
    - 여기서 putchar(ch) 대신 (1)((2), (3)) 이라고 해도 같은 결과를 얻을 수 있다. 또한 이 프로그램에서 이용한 FILENAME_MAX 는 "해당 개발 환경에서 열 수 있는 파일 이름의 최대 길이를 저장하는데 필요한 (4)" 이다.
    - (1): fputc
    - (2): ch
    - (3): stdout
    - (4): 배열의 요소 개수
*/


#include <stdio.h>


int main(void) {
    char ch;
    FILE *fp;
    char name[FILENAME_MAX];

    printf("파일 이름: ");
    scanf("%s", name);

    if ((fp = fopen(name, "r")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }

        fclose(fp);
    }

    return 0;
}