#include <stdio.h>
#include <ctype.h>


void put_upper(const char s[]) {
    int i = 0;

    while (s[i])
        putchar(toupper(s[i++]));
}

void put_lower(const char s[]) {
    int i = 0;

    while (s[i])
        putchar(tolower(s[i++]));
}

int main(void) {
    char str[128];

    printf("문자열을 입력해주세요: ");
    scanf("%s", str);

    printf("대문자: "); put_upper(str); putchar('\n');
    printf("소문자: "); put_lower(str); putchar('\n');

    return 0;
}