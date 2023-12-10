#include <stdio.h>


int main(void)
{
    int no;

    printf("input 1 number.");
    scanf("%d", &no);

    if (no >= 1) {
        while (no-- > 0)
        {
            putchar('*');
        }
        printf("\n");
    }

    return 0;
}