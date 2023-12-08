#include <stdio.h>


int main(void)
{
    int retry;

    do {
        int no;

        printf("input 1 number.");
        scanf("%d", &no);

        if (no == 0)
            puts("0");
        else if (no > 0)
            puts("+");
        else
            puts("-");
        
        printf("one more? [yes_0 / no_9]: ");
        scanf("%d", &retry);
    } while (retry == 0);

    return 0;
}