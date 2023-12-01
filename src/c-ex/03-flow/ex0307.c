#include <stdio.h>


int main(void)
{
    int n1, n2, n3, min;

    puts("input 3 number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);
    printf("n3 : ");
    scanf("%d", &n3);

    min = m1;

    if (n2 < min) min = n2;
    if (n3 < min) min = n3;

    printf("min : %d \n", min);

    return 0;
}