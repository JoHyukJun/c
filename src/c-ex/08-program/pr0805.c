/*
    - 다음은 x 의 2 제곱과 3 제곱을 구하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define sqr(x) (x * x)
#define cube(x) (x * x * x)


int main(void) {
    printf("sqr(3):\t\t%d\n", sqr(3));
    printf("cube(3):\t\t%d\n", cube(3));

    return 0;
}