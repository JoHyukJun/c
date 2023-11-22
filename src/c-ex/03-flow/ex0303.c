#include <stdio.h>


int main(void)
{
    int no;

    printf("input number.");
    scanf("%d", &no);

    if (no == 0)
        puts("0\n");
    else if (no > 0)
        puts("+\n");
    else if (no < 0)
        puts("-\n");
    
    return 0;
}