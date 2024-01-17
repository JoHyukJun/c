/*
    - 다음은 문자열 s 안의 숫자 문자 외 모든 문자를 삭제하는 (예를 들어 s 가 "AB7C5" 면 "75" 로 함) 함수다.
*/


#include <stdio.h>


void del_non_digit(char s[]) {
    int i = 0;
    int idx = 0;

    while (s[i]) {
        if (s[i] >= '0' && s[i] <= '9') {
            s[idx++] = s[i];
        }

        i++;
    }

    s[idx] = '\0';
}

int main(void) {
    char str[] = "ABC123DFS";
    char str2[] = "ABD1232134A";

    printf("str: %s\n", str);

    del_non_digit(str);
    printf("del_non_digit(str)\n");

    printf("str: %s\n", str);

    printf("str2: %s\n", str2);

    del_non_digit(str2);
    printf("del_non_digit(str2)\n");

    printf("str2: %s\n", str2);

    return 0;
}