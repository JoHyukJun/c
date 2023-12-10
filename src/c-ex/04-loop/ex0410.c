#include <stdio.h>


int main(void)
{
    int no;

    printf("input 1 number.");
    scanf("%d", &no);

    while (no-- > 0)
    {
        puts("*");
    }
    
    return 0;
}