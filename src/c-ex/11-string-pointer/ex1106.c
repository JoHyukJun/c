#include <stdio.h>


void put_string(const char *s) {
    while (*s)
        putchar(*s++);
}

int str_chnum(const char *s, int c) {
    int count = 0;

    while (*s)  {
        if (*s++ == c)
            count++;
    }

    return count;
}

int main(void) {
    char str[256];
    char ch[10];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    put_string(str);
    printf("에서 셀 문자는: ");
    scanf("%s", ch);

    printf("이 문자는 %d 개 포함되었습니다.\n", str_chnum(str, ch[0]));

    return 0;
}