#include <stdio.h>


int main(void)
{
    int no;

    printf("input 1 number.");
    scanf("%d", &no);

    if (no >= 0) {
        while (no >= 0)
        {
            printf("%d", no);
            no--;
        }
        printf("\n");
    }

    return 0;
}