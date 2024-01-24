#include <stdio.h>


void del_digit(char *str) {
    char *ptr = str;

    while (*str) {
        if (*str < '0' || *str > '9') {
            *ptr++ = *str;
        }

        str++;
    }

    *ptr = '\0';
}

int main(void) {
    char str[256];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    del_digit(str);

    puts("숫자 문자를 삭제했습니다.");
    printf("str = %s\n", str);

    return 0;
}