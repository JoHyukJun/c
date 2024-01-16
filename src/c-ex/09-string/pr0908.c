/*
    - 다음은 문자열 s 의 길이를 구해 반환하는 함수다.
*/


#include <stdio.h>


int str_length(const char s[]) {
    int len = 0;

    while (s[len])
        len++;

    return len;
}

int main(void) {
    char str[] = "AB123CD";

    printf("str: %s\n", str);

    printf("str_length(str): %d\n", str_length(str));

    return 0;
}