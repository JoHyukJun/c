/*
    - 다음은 문자열 s 가 빈 문자열이면 1을, 그렇지 않으면 0을 반환하는 함수다.
    - 첨자 연산자 없이 구현할 것.
*/


#include <stdio.h>


int is_null_string(const char *s) {
    return *s == 0 ? 1 : 0;
}

int main(void) {
    char *p = "123456";
    int is_null = -1;

    printf("p = \"%s\"\n", p);

    is_null = is_null_string(p);

    printf("is_null = %d\n", is_null);

    p[0] = '\0';

    is_null = is_null_string(p);

    printf("is_null = %d\n", is_null);

    return 0;
}