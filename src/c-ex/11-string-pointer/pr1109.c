/*
    - 다음은 문자열 s 안의 모든 문자열을 끝쪽에서 앞쪽으로 역순 출력하는 함수다.
*/


#include <stdio.h>


void putstr(const char *s) {
    char *p = s;

    while (*s) {
        s++;
    }

    while (s-- > p) {
        putchar(*s);
    }

    putchar('\n');
}

int main(void) {
    char *p = "abcdef";

    printf("p = \"%s\"\n", p);

    putstr(p);

    return 0;
}