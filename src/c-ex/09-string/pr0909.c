/*
    - 다음은 문자열 s 를 출력함과 동시에 그 길이를 반환하는 함수다.
*/


#include <stdio.h>


int str_put(const char s[]) {
    int i = 0;

    while (s[i]) {
        putchar(s[i]);
        i++;
    }

    putchar('\n');

    return i;
}

int main(void) {
    char str[] = "AB123CD";

    printf("str: %s\n", str);

    printf("str_put(str): %d\n", str_put(str));

    return 0;
}