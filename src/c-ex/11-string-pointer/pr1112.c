/*
    - 다음은 무자열 s1 과 s2 를 연결해 출력하는 함수다.
    - 예를 들어 s1 이 "ABC" 이고 s2 가 "DEF" 면 "ABCDEF" 라고 출력.
*/


#include <stdio.h>


void put_str_str(const char *s1, const char *s2) {
    while (*s1) {
        putchar(*s1++);
    }

    while (*s2) {
        putchar(*s2++);
    }

    putchar('\n');
}

int main(void) {
    char *s1 = "123";
    char *s2 = "456";

    put_str_str(s1, s2);

    return 0;
}