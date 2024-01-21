/*
    - 다음은 요소 개수가 5인 배열의 모든 요소에 0 을 대입하는 함수다.
*/


#include <stdio.h>


void setary0(int v[5]) {
    int i;

    for (i = 0; i < 5; i++)
        *(v + i) = 0;
}

int main(void) {
    int i;
    int x[] = {13, 3, 4, 3, 4};

    for (i = 0; i < 5; i++)
        printf("x[%d]: %d\n", i, x[i]);

    setary0(x);

    for (i = 0; i < 5; i++)
        printf("x[%d]: %d\n", i, x[i]);

    return 0;
}