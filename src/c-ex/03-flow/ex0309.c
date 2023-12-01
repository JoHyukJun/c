#include <stdio.h>


int main(void)
{
    int n1, n2, diff;

    puts("input 2 number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);

    if (n1 > n2)
        diff = n1 - n2;
    else
        diff = n2 - n1;

    printf("diff : %d \n", diff);

    return 0;
}