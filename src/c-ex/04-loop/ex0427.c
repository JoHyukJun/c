#include <stdio.h>


int main(void)
{
    int i, j, len;

    puts("왼쪽 아래가 직각인 직각이등변삼각형을 만듭니다.");
    printf("len: ");
    scanf("%d", &len);

    for (i = 1; i <= len; i++) {
        for (j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    puts("왼쪽 위가 직각인 직각이등변삼각형을 만듭니다.");
    printf("len: ");
    scanf("%d", &len);

    for (i = len; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    puts("오른쪽 아래가 직각인 직각이등변삼각형을 만듭니다.");
    printf("len: ");
    scanf("%d", &len);

    for (i = 1; i <= len; i++) {
        for (j = 1; j <= len - i; j++) {
            putchar(' ');
        }
        for (j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    puts("오른쪽 위가 직각인 직각이등변삼각형을 만듭니다.");
    printf("len: ");
    scanf("%d", &len);

    for (i = len; i >= 1; i--) {
        for (j = 1; j <= len - i; j++) {
            putchar(' ');
        }
        for (j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}