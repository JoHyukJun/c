#include <stdio.h>


int main(void)
{
    int a, b, h;

    puts("size");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &h);

    printf("%f\n", (a + b) * h / 2.0);

    return 0;
}