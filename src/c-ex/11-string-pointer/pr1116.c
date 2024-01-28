/*
    - 다음은 문자열 s1 뒤에 마지막 널 문자를 포함하여 문자열 s2 를 연결한 다음, 전달받은 s1 과 똑같은 값을 반환하는 함수다.
*/


#include <stdio.h>


char *str_cat(char *s1, const char *s2) {
    char *tmp = s1;

    while (*s1)
        *s1++;

    while(*s1++ = *s2++)
        ;

    return tmp;
}

int main(void) {
    char s1[128] = "123";
    char s2[128] = "456";
    char *res;

    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);

    res = str_cat(s1, s2);

    printf("s1 = \"%s\"\n", s1);
    printf("res = \"%s\"\n", res);

    return 0;
}