/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        a[0][0] = 2
        a[0][1] = 2
        a[1][0] = 0
        a[1][1] = 0
*/


#include <stdio.h>


int main(void) {
    int a[2][2] = {2, 2};
    int i, j;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);

    return 0;
}