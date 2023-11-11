#include <stdio.h>


int main(void)
{
    int x, y;

    puts("input 2 number.");
    printf("x : ");
    scanf("%d", &x);
    printf("y : ");
    scanf("%d", &y);

    printf("100 * x / y = %d\n", 100 * x / y);

    return 0;
}