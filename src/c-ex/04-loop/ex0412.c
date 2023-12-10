#include <stdio.h>


int main(void)
{
    int no;

    do {
        printf("input 1 number.");
        scanf("%d", &no);

        if (no <= 0)
            puts("input positive number");
    } while(no <= 0)

    printf("reverse %d: ", no);

    while (no > 0)
    {
        printf("%d", no % 10);
        no /= 10;
    }

    return 0;
}