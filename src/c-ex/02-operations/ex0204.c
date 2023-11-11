#include <stdio.h>


int main(void)
{
    int a, b;

    puts("input 2 number.");
    printf("a : ");
    scanf("%d", &a);
    printf("b : ");
    scanf("%d", &b);

    printf("a + b = %d , a * b = %d\n", a + b, a * b);

    return 0;
}