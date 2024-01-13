#include <stdio.h>


int main(void) {
    char s[] = "ABC";
    char str[48];

    printf("문자열 str : ");
    scanf("%s", str);

    printf("문자열 s 은 \"%s\" 입니다.\n", s);
    printf("문자열 str 은 \"%s\" 입니다.\n", str);

    s[0] = '\0';
    str[0] = '\0';

    printf("문자열 s 은 \"%s\" 입니다.\n", s);
    printf("문자열 str 은 \"%s\" 입니다.\n", str);

    return 0;
}