#include <stdio.h>
#include <ctype.h>


void str_toupper(char *s) {
    while (*s) {
        *s = toupper(*s);
        s++;
    }
}

void str_tolower(char *s) {
    while (*s) {
        *s = tolower(*s);
        s++;
    }
}

int main(void) {
    char str[128];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    str_toupper(str);
    printf("대문자: %s\n", str);

    str_tolower(str);
    printf("소문자: %s\n", str);

    return 0;
}