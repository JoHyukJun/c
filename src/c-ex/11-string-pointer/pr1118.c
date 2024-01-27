/*
    - 다음은 문자열 s 안의 숫자 문자만 출력 (예를 들어 s 가 "740GT635" 면 "740635" 를 출력) 하는 함수다.
*/


#include <stdio.h>


void put_strdgt(const char *s) {
    while (*s) {
        if (*s >= '0' && *s < '9') {
            putchar(*s);
        }
        *s++;
    }

    putchar('\n');
}

int main(void) {
    char s1[128] = "740GT635";

    printf("s1 = \"%s\"\n", s1);

    put_strdgt(s1);

    return 0;
}