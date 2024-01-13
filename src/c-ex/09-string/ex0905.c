#include <stdio.h>


void null_string(char s[]) {
    s[0] = '\0';
}

int main(void) {
    char str[128];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    printf("문자열 str 은 \"%s\" 입니다.\n", str);
    null_string(str);
    printf("문자열 str 은 \"%s\" 입니다.\n", str);

    return 0;
}