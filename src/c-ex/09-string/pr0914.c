/*
    - 다음은 요소 개수가 n 인 문자열(요소 개수가 10이고 요소형이 char 형인 char[10] 형 배열) 배열 v 의 각 문자열을 출력하는 함수다.
*/


#include <stdio.h>

#define LEN 10


void put_str10ary(const char v[][10], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("v[%d] = \"%s\"\n", i, v[i]);
}

void put_str10ary_2(const char v[][10], int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        printf("v[%d] = \"", i);

        for (j = 0; v[i][j] != '\0'; j++) {
            putchar(v[i][j]);
        }

        printf("\"\n");
    }
}

int main(void) {
    char cs[][LEN] = {"SEC", "ABC", "12345"};

    put_str10ary(cs, 3);
    put_str10ary_2(cs, 3);

    return 0;
}