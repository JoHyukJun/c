#include <stdio.h>


int main(void)
{
    int no;

    printf("input 1 number.");
    scanf("%d", &no);

    if (no >= 1) {
        int i = 1;
        while (i <= no)
        {
            printf("%d", i++);
        }
        printf("\n");
    }

    return 0;
}