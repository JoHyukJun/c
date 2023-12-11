#include <stdio.h>


int main(void)
{
    int i, j;
    int height;

    puts("rect");
    printf("height: ");
    scanf("%d", &height);

    for (i = 1; i <= height; i++) {
        for (j = 1; j <= height; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}