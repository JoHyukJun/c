/*
    - 다음은 문자열 s1 과 문자열 s2 가 같으면 (모든 문자가 동일하다면) 1을 반환하고 그렇지 않으면 0 을 반환하는 함수다.
*/


#include <stdio.h>


int str_eq(const char s1[], const char s2[]) {
    int i = 0;

    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0')
            return 1;
    }

    return 0;
}

int main(void) {
    char str1[] = "ABCBC";
    char str2[] = "ABCBC";
    char str3[] = "BCAAA";

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    printf("str_eq(str1, str2): %d\n", str_eq(str1, str2));
    printf("str_eq(str1, str3): %d\n", str_eq(str1, str3));
    printf("str_eq(str2, str3): %d\n", str_eq(str2, str3));

    return 0;
}