/*
    - 다음은 요소 개수가 n 개인 int 형 배열 a 의 보든 요소 값(값은 모두 양수)을 기호 문자 * 를 가로로 나열한 그래프로 출력하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int n = 5;
    int a[n];
    int i, j;

    for (i = 0; i < n; i++)
        a[i] = i;

    for (i = 0; i < n; i++) {
        printf("a[%d]: ", i);

        for (j = 0; j < a[i]; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}