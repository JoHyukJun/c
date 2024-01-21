/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        *ptr = 100
        x = 400
        y = 500
*/


#include <stdio.h>


int main(void) {
    int x = 100;
    int y = 500;
    int *ptr = &x;

    printf("*ptr = %d\n", *ptr);

    *ptr = 400;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}