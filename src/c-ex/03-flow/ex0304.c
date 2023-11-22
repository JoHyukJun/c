#include <stdio.h>


int main(void)
{
    int no;

    printf("input number.");
    scanf("%d", &no);

    if (no < 0)
        num = -num;

    printf("abs val: %d\n", no);
    
    return 0;
}