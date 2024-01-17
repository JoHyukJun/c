/*
    - 다음은 문자열 s1 에 문자열 s2 를 복사하는 함수다.
*/


#include <stdio.h>

#define LEN 128


void str_copy(char s1[], char s2[]) {
    int i = 0;

    for (i = 0; i < s2[i]; i++) {
        s1[i] = s2[i];
    }

    s1[i] = '\0';
}

int main(void) {
    char str[LEN];
    char str2[] = "ABD1232134A";

    printf("str2: %s\n", str2);

    str_copy(str, str2);

    printf("str: %s\n", str);

    return 0;
}