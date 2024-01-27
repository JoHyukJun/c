/*
    - 다음은 문자열 s 의 길이 (널 문자는 포함하지 않은 문자 개수) 를 구하여 반환하는 함수다.
*/


#include <stdio.h>


int str_len(const char *s) {
    int len = 0;

    while (*s++)
        len++;

    return len;
}

int main(void) {
    int plen;
    char *p = "123456";

    printf("p = \"%s\"\n", p);

    plen = str_len(p);

    printf("plen = %d\n", plen);

    return 0;
}