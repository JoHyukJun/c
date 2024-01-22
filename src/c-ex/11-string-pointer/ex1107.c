#include <stdio.h>


char *str_chr(const char *s, int c) {
    while (*s) {
        if (*s == c) {
            return s;
        }

        s++;
    }

    return NULL;
}

int main(void) {
    char str[256];
    char ch[10];
    char *p;

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    printf("검색할 문자는: ");
    scanf("%s", ch);

    if ((p = str_chr(str, ch[0])) == NULL) {
        printf("이 문자는 포함되지 않았습니다.\n");
    }
    else {
        printf("이 이후의 문자는 %s 입니다.\n", p);
    }

    return 0;
}