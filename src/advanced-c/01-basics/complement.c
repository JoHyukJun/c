#include <stdio.h>


int main (void)
{
    int a = 0x00112233;

    printf("0x%08X\n", a);
    printf("%d\n", 10 - 5);
    printf("%d\n", 10 + (~5 + 1));

    return 0;
}