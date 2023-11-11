#include <stdio.h>


int main(void)
{
    int x, y;
    int ave;

    puts("input 2 number.");
    printf("x : ");
    scanf("%d", &x);
    printf("y : ");
    scanf("%d", &y);

    ave = (x + y) / 2;

    printf("-1 * (x + y) / 2 = %d\n", -ave);

    return 0;
}