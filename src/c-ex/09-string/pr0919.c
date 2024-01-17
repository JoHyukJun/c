/*
    - 다음은 문자열 s2 에 포함되지 않은 모든 문자를 문자열 s1 에서 삭제하는 함수다.
    - 예를 들어 s1 이 "ABCKCAE" 고 s2 가 "ACE" 면 s1 을 "ACCAE" 로 한다.
*/


#include <stdio.h>


void str_rmv(char s1[], const char s2[]) {
    int i, j;
    int idx = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                s1[idx++] = s1[i];
                break;
            }
        }
    }

    s1[idx] = '\0';
}

int main(void) {
    char str1[] = "ABCKCAE";
    char str2[] = "ACE";

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    printf("str_rmv(str1, str2) ->\n");

    str_rmv(str1, str2);

    printf("str1: %s\n", str1);

    return 0;
}