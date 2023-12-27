/*
    - 다음은 배열 a 의 앞쪽 n 개 요소에 v 를 대입하는 함수와 그 함수를 이용해 배열 x 의 모든 요소에 0 을 대입하는 함수다.
*/


#include <stdio.h>

#define NUMBER 5


void fill(int a[], int n, int v) {
    int i;

    for (i = 0; i < n; i++) {
        a[i] = v;
    }
}

void fill0(int a[], int n) {
    fill(a, n, 0);
}

int main(void) {
    int i;
    int a[NUMBER] = {3, 4, 5, -1, -2};

    fill(a, NUMBER, 5);

    for (i = 0; i < NUMBER; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    fill0(a, NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    return 0;
}