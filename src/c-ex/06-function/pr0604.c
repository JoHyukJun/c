/*
    - 다음 프로그램의 실행 결과를 나타내라.
    ->
        52 15 37
*/


#include <stdio.h>


int test(int x, int y) {
    int temp = x + y;
    x = 0;
    y = 0;

    return temp;
}

int main(void) {
    int n1 = 15, n2 = 37;

    printf("%d ", test(n1, n2));
    printf("%d %d\n", n1, n2);

    return 0;
}