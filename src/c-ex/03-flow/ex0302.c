#include <stdio.h>


int main(void)
{
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    if (a % b)
        puts("measure");
    else
        puts("not measuer");

    return 0;
}