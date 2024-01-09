/*
    - 다음은 x 와 y 의 차이를 구하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define diff(x, y) (((x) > (y)) ? x - y : y - x)


int main(void) {
    printf("diff(3, 4): \t%d\n", diff(3, 4));
    printf("diff(6, 4): \t%d\n", diff(6, 4));

    return 0;
}