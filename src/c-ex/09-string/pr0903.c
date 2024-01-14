/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        1
        3
        4
*/


#include <stdio.h>


int main(void) {
    printf("%u\n", (unsigned)sizeof(""));
    printf("%u\n", (unsigned)sizeof("X6"));
    printf("%u\n", (unsigned)sizeof("X\0X"));

    return 0;
}