/*
    - 다음은 2개의 정숫값 x 와 y 의 최대 공약수를 구해 반환하는 함수다.
*/


#include <stdio.h>


int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main(void) {
    printf("gcd(4, 8):%d\n", gcd(4, 8));
    printf("gcd(3, 6):%d\n", gcd(3, 6));

    return 0;
}