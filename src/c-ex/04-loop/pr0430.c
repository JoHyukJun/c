/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        Hello! 1
        Hello! 2
        Hello! 3
*/


#include <stdio.h>


int main(void) {
    int i;

    for (i = 1; i <= 3; i++)
        printf("Hello! %d\n", i);

    return 0;
}