/*
    - 다음은 문자열 s 를 빈 문자열로 만드는 처리를 첨자 연산자 없이 구현하는 함수다.
*/


#include <stdio.h>


void null_string(char *s) {
    s[0] = '\0';
}

int main(void) {
    char *p = "123";

    printf("p = \"%s\"\n", p);

    null_string(p);

    printf("p = \"%s\"\n", p);

    return 0;
}