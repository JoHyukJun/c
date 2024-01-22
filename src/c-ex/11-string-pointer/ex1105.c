#include <stdio.h>


void put_string(const char *s) {
    while (*s)
        putchar(*s++);
}

int main(void) {
    char str[256];
    char ch[10];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    put_string(str);

    return 0;
}