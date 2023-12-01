#include <stdio.h>


int main(void)
{
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    puts("eql");
    printf("a == b : %d", a == b);
    printf("a != b : %d", a != b);

    puts("diff");
    printf("a < b : %d", a < b);
    printf("a <= b : %d", a <= b);
    printf("a > b : %d", a > b);
    printf("a >= b : %d", a >= b);

    return 0;
}