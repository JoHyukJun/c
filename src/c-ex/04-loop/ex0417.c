#include <stdio.h>


int main(void)
{
    int no, i;

    printf("input 1 number.");
    scanf("%d", &no);

    for (i = 1; i <= no; i += 2)
        printf("%d", i)
    putchar('\n');

    return 0;
}