#include <stdio.h>


int main(void)
{
    double a, b;

    puts("input float number: ");
    printf("a : ");
    scanf("%lf", &a);
    printf("b : ");
    scanf("%lf", &b);

    printf("a / b * 100 = %f\n", a / b * 100);

    return 0;
}