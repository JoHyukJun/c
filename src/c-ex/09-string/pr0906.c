/*
    - 다음은 문자열 s 의 내용이 "ABC" 면 1 을 반환하고 그렇지 않으면 0 을 반환하는 함수다.
*/


#include <stdio.h>


int isABC(const char s[]) {
    if (s[0] != 'A') return 0;
    if (s[1] != 'B') return 0;
    if (s[2] != 'C') return 0;
    if (s[3] != '\0') return 0;

    return 1;
}

int main(void) {
    char str[] = "test";
    char str2[] = "ABC";

    printf("str: %s\n", str);

    printf("isABC(str): %d\n", isABC(str));

    printf("str2: %s\n", str2);

    printf("isABC(str2): %d\n", isABC(str2));

    return 0;
}