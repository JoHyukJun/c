#include <stdio.h>

#define diff(x, y) (((x) > (y)) ? ((x) - (y)) : ((y) - (x)))


int main(void) {
    int a, b;

    puts("2개의 정수를 입력하세요.");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("diff: %d\n", diff(a, b));

    return 0;
}