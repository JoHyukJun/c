#include <stdio.h>


int min3(int a, int b, int c) {
    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main(void) {
    int a, b, c;

    puts("input 3 number.");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    printf("min val: %d\n", min3(a, b, c));

    return 0;
}