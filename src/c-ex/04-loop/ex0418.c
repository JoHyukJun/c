#include <stdio.h>


int main(void)
{
    int no, i;

    printf("input 1 number.");
    scanf("%d", &no);

    for (i = 1; i <= no; i++)
        printf("%d\n", i * i)

    return 0;
}