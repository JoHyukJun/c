/*
    - 다음은 문자열 s 를 작은따옴표(')로 감싸 출력하는 함수다.
*/


#include <stdio.h>


void putstr(const char *s) {
    putchar('\'');

    while(*s) {
        putchar(*s++);
    }
    putchar('\'');
}

int main(void) {
    char *p = "ABC";

    printf("p = \"%s\"\n", p);

    putstr(p);

    return 0;
}