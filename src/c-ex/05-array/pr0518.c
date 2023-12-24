/*
    - 다음은 요소 개수가 n 개인 배열 a 의 모든 요소 순서를 반전하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int n = 5;
    int a[n];
    int i;

    for (i = 0; i < n; i++)
        a[i] = i;

    for (i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    for (i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    putchar('\n');

    for (i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    return 0;
}