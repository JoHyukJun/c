#include <stdio.h>


int main(void)
{
    int no, temp;
    int digits;

    do {
        printf("input 1 number.");
        scanf("%d", &no);

        if (no <= 0)
            puts("input positive number");
    } while(no <= 0)

    temp = no;
    digits = 0;

    while (temp > 0)
    {
        temp /= 10;
        digits++;
    }

    printf("digits: %d\n", digits);

    return 0;
}