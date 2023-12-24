/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        a[0] = 5
        a[1] = 4
        a[2] = 3
        a[3] = 2
        a[4] = 1
*/


#include <stdio.h>


int main(void) {
    int a[5] = {5, 4, 3, 2, 1};
    int i;

    for (i = 0; i < 5; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}