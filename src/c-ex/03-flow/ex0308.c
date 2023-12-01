#include <stdio.h>


int main(void)
{
    int n1, n2, n3, n4, max;

    puts("input 3 number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);
    printf("n3 : ");
    scanf("%d", &n3);
    printf("n4 : ");
    scanf("%d", &n4);

    max = n1;

    if (n2 > min) max = n2;
    if (n3 > min) max = n3;
    if (n4 > min) max = n4;

    printf("max : %d \n", max);

    return 0;
}