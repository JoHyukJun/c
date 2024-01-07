#include <stdio.h>


int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int main(void) {
    int x, y;

    puts("2개의 정숫값의 최대 공약수를 구합니다.");
    printf("x: "); scanf("%d", &x);
    printf("y: "); scanf("%d", &y);

    printf("gcd:%d\n", gcd(x, y));

    return 0;
}