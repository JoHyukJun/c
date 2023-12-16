/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        3 : 
        4 : 2 
        5 : 
        6 : 2 3 
        7 : 
        8 : 2 4 
        9 : 3 
        10 : 2 5 
        11 : 
        12 : 2 3 4 6 
        13 : 
        14 : 2 7 
        15 : 3 5 
*/


#include <stdio.h>


int main(void) {
    int i, j;

    for (i = 3; i <= 15; i++) {
        printf("%d : ", i);

        for (j = 2; j < i; j++) {
            if (i % j != 0)
                continue;
            printf("%d ", j);
        }

        putchar('\n');
    }

    return 0;
}