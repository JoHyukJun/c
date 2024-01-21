/*
    - 요소 개수가 10 이고 요소형인 int 인 배열 x 로 setary0(x) 라고 호출하면 (1).
    - (1): 배열 x 의 앞쪽 5개 요소에 0 이 대입된다
*/


#include <stdio.h>


void setary0(int v[5]) {
    int i;

    for (i = 0; i < 5; i++)
        *(v + i) = 0;
}

int main(void) {
    int i;
    int x[] = {13, 3, 4, 3, 4, 3, 4, 5, 6, 7, 8};

    for (i = 0; i < 10; i++)
        printf("x[%d]: %d\n", i, x[i]);

    setary0(x);

    for (i = 0; i < 10; i++)
        printf("x[%d]: %d\n", i, x[i]);

    return 0;
}