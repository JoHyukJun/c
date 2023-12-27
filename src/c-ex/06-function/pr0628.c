/*
    - 다음은 배열 b 의 앞쪽부터 n 개의 요소를 배열 a 에 복사하는 함수다.
*/


#include <stdio.h>

#define NUMBER 5


void cpy_ary(int a[], const int b[], int n) {
    int i;

    for (i = 0; i < n; i++) 
        a[i] = b[i];
}

int main(void) {
    int i;
    int a[NUMBER];
    int b[NUMBER + 1] = {3, 4, 5, -1, -2, 3};

    for (i = 0; i < NUMBER; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    cpy_ary(a, b, NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }

    return 0;
}