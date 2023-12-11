#include <stdio.h>


int main(void)
{
    int i, j;
    int h;

    puts("피라미드를 만듭니다.");
    printf("h: ");
    scanf("%d", &h);

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= h - i; j++) {
            putchar(' ');
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}