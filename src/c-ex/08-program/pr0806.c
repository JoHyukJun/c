/*
    - 다음은 x 의 절댓값을 구하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define abx(x) (((x) > 0) ? x : -x)

int main(void) {
    printf("abx(3): \t%d\n", abx(3));
    printf("abx(-3):\t%d\n", abx(-3));

    return 0;
}