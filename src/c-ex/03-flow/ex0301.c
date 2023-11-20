#include <stdio.h>


int main(void)
{
    int no;

    printf("input number: ");
    scanf("%d", &no);

    if (no % 10)
        puts("not 10 mul\n");

    return 0;
}