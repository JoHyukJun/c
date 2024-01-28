/*
    - 다음은 문자열 s1 과 s2 를 교환하는 함수다.
*/


#include <stdio.h>


void swap_string(char *s1, char *s2) {
    char *temp;

    while (*s1 && *s2) {
        char t = *s1;
        *s1++ = *s2;
        *s2++ = t;
    }

    if (*s1) {
        temp = s1;

        while (*s1) {
            *s2++ = *s1++;
        }

        *temp = *s2 = '\0';
    }
    else if (*s2) {
        temp = s2;

        while (*s2) {
            *s1++ = *s2++;
        }

        *temp = *s1 = '\0';
    }
}

int main(void) {
    char s1[128] = "123123";
    char s2[128] = "456";

    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);

    swap_string(s1, s2);

    printf("s1 = \"%s\"\n", s1);
    printf("s2 = \"%s\"\n", s2);

    return 0;
}