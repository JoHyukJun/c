#include <stdio.h>


int main(void)
{
    int i, j;
    int h;

    puts("아래로 향한 숫자 피라미드를 만듭니다.");
    printf("h: ");
    scanf("%d", &h);

    for (i = 1; i <= h; i++) {
        for (j = 1; j <= i - 1; j++) {
            putchar(' ');
        }
        for (j = 1; j <= 2 * (h - i) + 1; j++) {
            printf("%d", i % 10);
        }
        putchar('\n');
    }

    return 0;
}