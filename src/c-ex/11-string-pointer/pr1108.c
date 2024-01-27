/*
    - 다음은 문자열 s 가 "ABC" 면 1을, 그렇지 않으면 0을 반환하는 함수다.
    - 첨자 연산자 없이 구현할 것.
*/


#include <stdio.h>


int is_ABC(const char *s) {
    if (*s++ != 'A') return 0;
    if (*s++ != 'B') return 0;
    if (*s++ != 'C') return 0;
    
    return 1;
}

int main(void) {
    char *p = "ABC";
    int isABC = -1;

    printf("p = \"%s\"\n", p);

    isABC = is_ABC(p);

    printf("isABC = %d\n", isABC);

    p = "BCA";

    isABC = is_ABC(p);

    printf("isABC = %d\n", isABC);

    return 0;
}