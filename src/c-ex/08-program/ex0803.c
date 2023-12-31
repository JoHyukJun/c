#include <stdio.h>

#define swap(type, a, b) do { type t = a; a = b; b = t; } while (0)


int main(void) {
    int x, y;
    double a, b;

    puts("2개의 정수를 입력하시오.");
    printf("x: "); scanf("%d", &x);
    printf("y: "); scanf("%d", &y);

    swap(int, x, y);
    printf("swap: x: %d y: %d\n", x, y);

    puts("2개의 실수를 입력하시오.");
    printf("a: "); scanf("%lf", &a);
    printf("b: "); scanf("%lf", &b);

    swap(double, a, b);
    printf("swap: a: %0.3f b: %0.3f\n", a, b);

    return 0;
}