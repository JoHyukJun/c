#include <stdio.h>


int main(void)
{
    int n1, n2, diff;

    puts("input 2 number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);

    diff = n1 - n2;

    if (diff > 10 && diff < -10)
        puts("over 11 diff");
    else
        puts("under 11 diff");
        
    return 0;
}