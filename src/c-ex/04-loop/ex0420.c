#include <stdio.h>


int main(void)
{
    int no, i, count;

    printf("input 1 number.");
    scanf("%d", &no);

    count = 0;
    
    for (i = 1; i <= no, i++)
        if (n % i == 0) {
            printf("%d\n", i);
            count++;
        }

    printf("%d\n", count);

    return 0;
}