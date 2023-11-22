#include <stdio.h>


int main(void)
{
    int no;

    printf("input number.");
    scanf("%d", &no);

    if (no == 0)
        puts("0");
    else if (no > 0)
        puts("+");
    else if (no < 0)
        puts("-");
    
    return 0;
}