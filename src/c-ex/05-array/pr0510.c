/*
    - 다음은 요소 개수가 n 인 배열 y 열의 모든 요소 값을 배열 x 로 복사하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int i, n;

    puts("input arr size.");
    scanf("%d", &n);

    int x[n], y[n];

    for (i = 0; i < n; i++)
        y[i] = i + 1;

    for (i = 0; i < n; i++)
        x[i] = y[i];

    return 0;
}