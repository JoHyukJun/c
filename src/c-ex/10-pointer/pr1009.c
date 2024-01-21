/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        25
*/


#include <stdio.h>


int main(void) {
    int x = 5;
    int *p = &x;

    printf("%d", 5 * *p);

    return 0;
}