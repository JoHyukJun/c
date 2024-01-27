/*
    - 다음은 문자열 s 를 d 로 복사한 다음, 전달받은 d 와 똑같은 값을 반환하는 함수다.
*/


#include <stdio.h>


char *str_copy(char *d, const char *s) {
    char *t = d;

    while (*d++ = *s++) {
        putchar(*s);
    }

    putchar('\n');

    return t;
}

int main(void) {
    char *p = "ABC";
    char s1[10];
    char *s2;

    printf("p = \"%s\"\n", p);

    s2 = str_copy(s1, p);

    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);

    return 0;
}