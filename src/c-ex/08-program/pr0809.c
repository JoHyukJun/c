/*
    - 앞 문제의 diff 를 호출하는 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        11
        14
*/


#include <stdio.h>

#define diff(x, y) (((x) > (y)) ? x - y : y - x)


int main(void) {
    int x = 15, y = 5;

    printf("%d\n", diff(x++,y));
    printf("%d\n", diff(++x, y));

    return 0;
}