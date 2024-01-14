/*
    - 다음은 이름을 나타내는 문자열을 name 에 읽어 들여 인사를 출력하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    char name[128];

    printf("May I have your name: ");
    scanf("%s", name);

    printf("Hello, %s!!\n", name);

    return 0;
}