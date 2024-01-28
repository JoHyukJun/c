/*
    - 다음은 문자열 s 의 문자 나열을 반전하는 함수다.
*/


#include <stdio.h>


void rev_string(char *s) {
    char *p = s;

    while (*p) {
        p++;
    }

    if (p != s) {
        p--;

        while (p > s) {
            putchar(*p);
            putchar('\n');
            putchar(*s);
            putchar('\n');
            char temp = *p;
            *p-- = *s;
            *s++ = temp;
        }
    }
}

int main(void) {
    char s1[128] = "123";

    printf("s1 = \"%s\"\n", s1);

    rev_string(s1);

    printf("s1 = \"%s\"\n", s1);

    return 0;
}