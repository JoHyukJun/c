#include <stdio.h>


int str_chnum(const char s[], int c) {
    int i;
    int count = 0;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            count++;

    return count;
}

void put_stringn(const char s[], int n) {
    while (n-- > 0)
        printf("%s", s);
}

int str_length(const char s[]) {
    int len = 0;

    while (s[len])
        len++;

    return len;
}

void put_stringr(const char s[]) {
    int i = str_length(s);

    while (i-- > 0)
        putchar(s[i]);
}

int main(void) {
    char str[256], ch[256];

    printf("문자열 str 을 입력해주세요: ");
    scanf("%s", str);

    printf("문자 ch 을 입력해주세요: ");
    scanf("%s", ch);

    printf("str 은 ch 를 %d 개 포함합니다.\n", str_chnum(str, ch[0]));

    put_stringn(str, 3);

    putchar('\n');

    put_stringr(str);

    return 0;
}