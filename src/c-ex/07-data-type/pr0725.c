/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        x + 1 = 0
        x + 7 = 6
*/


#include <stdio.h>
#include <limits.h>


int main(void) {
    unsigned x = UINT_MAX;

    printf("x + 1 = %u\n", x + 1);
    printf("x + 7 = %u\n", x + 7);

    return 0;
}