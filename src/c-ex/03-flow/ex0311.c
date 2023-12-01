#include <stdio.h>


int main(void)
{
    int n1, n2, n3;

    puts("input 3 number.");
    printf("n1 : ");
    scanf("%d", &n1);
    printf("n2 : ");
    scanf("%d", &n2);
    printf("n3 : ");
    scanf("%d", &n3);

    if (n1 == n2 && n2 == n3)
        puts("all eql");
    else if (n1 == n2 || n2 == n3 || n3 == n1)
        puts("2 eql");
    else
        puts("all diff");
        
    return 0;
}