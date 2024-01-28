/*
    - 다음은 문자열 s 안의 모든 영문 소문자를 영문 대문자로 변환하는 함수다.
    - 이 함수를 컴파일하려면 (1) 헤더가 필요하다.
    - (1): ctype.h
*/


#include <stdio.h>
#include <ctype.h>


void str_toupper(char *s) {
    while (*s) {
        *s = toupper(*s);
        putchar(*s);
        *s++;
    }

    putchar('\n');
}

int main(void) {
    char s1[128] = "abcdafsfaewf";

    printf("s1 = \"%s\"\n", s1);

    str_toupper(s1);

    return 0;
}