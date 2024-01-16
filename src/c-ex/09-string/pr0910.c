/*
    - 다음은 문자열 s 의 끝 문자에서 앞 문자까지 역순으로 출력하는 (예를 들어 s 가 "ABC" 면 "CBA" 라고 출력) 함과 동시에 그 길이를 반환하는 함수다.
*/


#include <stdio.h>


int str_putr(const char s[]) {
    int i, len = 0;

    while (s[len])
        len++;

    i = len;

    while (i-- > 0)
        putchar(s[i]);

    putchar('\n');

    return len;
}

int main(void) {
    char str[] = "AB123CD";

    printf("str: %s\n", str);

    printf("str_putr(str): %d\n", str_putr(str));

    return 0;
}