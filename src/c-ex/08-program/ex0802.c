#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))


int main(void) {
    int a, b, c, d;

    puts("4개의 정수를 입력하시오.");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);
    printf("d: "); scanf("%d", &d);

    printf("max: %d\n", max(max(a, b), max(c, d)));
    printf("max: %d\n", max(max(max(a, b), c), d));

    return 0;
}