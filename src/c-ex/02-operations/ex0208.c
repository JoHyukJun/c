#include <stdio.h>


int main(void)
{
    int n1, n2;
    double d1, d2;

    puts("input number and float number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);
    printf("d1 : ");
    scanf("%lf", &d1);
    printf("d2 : ");
    scanf("%lf", &d2);

    printf("%d * 2 = %d\n", n1, n1 * 2);
    printf("%d / 2 = %d\n", n1, n1 / 2);
    printf("%d * %d = %d\n", n1, n2,  n1 * n2);
    printf("%d / %d = %d\n", n1, n2, n1 / n2);

    printf("%d * 2.5 = %d\n", n1, n1 * 2.5);
    printf("%d / 2.5 = %d\n", n1, n1 / 2.5);
    printf("%d * %f = %f\n", n1, d1,  n1 * d1);
    printf("%d / %f = %f\n", n1, d1, n1 / d1);

    printf("%f * %f = %f\n", d1, d2, d1 * d2);
    printf("%f / %f = %f\n", d1, d2, d1 / d2);

    return 0;
}