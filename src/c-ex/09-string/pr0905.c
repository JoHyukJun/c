/*
    - 다음은 인수로 전달받은 문자열 s 를 빈 문자열로 하는 함수다.
*/


#include <stdio.h>


void null_string(char s[]) {
    s[0] = '\0';
}

int main(void) {
    char str[] = "test";

    printf("str: %s\n", str);

    null_string(str);

    printf("str: %s\n", str);

    return 0;
}