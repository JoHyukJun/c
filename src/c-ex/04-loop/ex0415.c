#include <stdio.h>


int main(void)
{
    int no, i;

    printf("input 1 number.");
    scanf("%d", &no);

    for (i = 1; i <= no; i++)
        printf("%d", i % 10);
    putchar('\n');

    int r, q;

    printf("input 1 number.");
    scanf("%d", &no);

    q = no / 10;
    r = no % 10;

    for (i = 1; i <= q; i++)
        printf("1234567890");
    for (i = 1; i <= r; i++)
        printf("%d", i % 10);
    putchar('\n');

    return 0;
}