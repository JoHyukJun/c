/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        S
        C
        3
        6
    - 또한 p[1] 은 (1) 를 저장한 주소로 초기화 한다.
    - (1): "5"
*/


#include <stdio.h>


int main(void) {
    char s[][5] = {"LSIP", "C", "Ada"};
    char *p[] = {"1234", "5", "678"};

    putchar(s[0][1]); putchar('\n');
    putchar(s[1][0]); putchar('\n');
    putchar(p[0][2]); putchar('\n');
    putchar(p[2][0]); putchar('\n');

    return 0;
}