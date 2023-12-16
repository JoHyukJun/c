/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        2 3 4 5 6 7 
        1 3 4 5 6 7 
        1 2 4 5 6 7 
        1 2 3 5 6 7 
        1 2 3 4 6 7 
        1 2 3 4 5 7 
        1 2 3 4 5 6
*/


#include <stdio.h>


int main(void) {
    int i, j;

    for (i = 1; i <= 7; i++) {
        for (j = 1; j <= 7; j++) {
            if (i != j)
                printf("%d ", j);
        }
        putchar('\n');
    }

    return 0;
}