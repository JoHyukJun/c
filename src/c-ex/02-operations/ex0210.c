#include <stdio.h>


int main(void)
{
    double a, b;

    puts("input 2 number: ");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("(double)a / b * 100.0 = %f\n", (double)a / b * 100.0);

    return 0;
}