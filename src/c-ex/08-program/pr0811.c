/*
    - 다음은 앞 문제의 swap 을 이용해 double 형 배열 v 의 요소 나열을 반전하는 함수다.
*/


#include <stdio.h>

#define NUMBER 5

#define swap(type, x, y) do {type t = x; x = y; y = t; } while(0)


void reverse(double v[], int n) {
    int i;

    for (i = 0; i < n / 2; i++)
        swap(double, v[i], v[n - i - 1]);
}

int main(void) {
    int i;
    double varr[NUMBER] = {1.1, 2.2, 3.3, 4.4, 5.5};

    for (i = 0; i < NUMBER; i++)
        printf("varr[%d]:%lf\n", i, varr[i]);

    printf("########################\n");

    reverse(varr, NUMBER);

    for (i = 0; i < NUMBER; i++)
        printf("varr[%d]:%lf\n", i, varr[i]);

    return 0;
}