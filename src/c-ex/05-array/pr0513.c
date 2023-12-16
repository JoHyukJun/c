/*
    - 다음은 요소 개수가 n 인 배열 a 의 모든 요수 첨자와 값을 출력하는 프로그램 일부다.
*/


#include <stdio.h>

#define n 5


int main(void) {
    int i;

    int a[n];

    for (i = 0; i < n; i++)
        a[i] = i + 1;

    for (i = 0; i < n; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}