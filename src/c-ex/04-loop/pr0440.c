/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        3 : 2 
        4 : 2 
        5 : 2 3 4 
        6 : 2 
        7 : 2 3 4 5 6 
        8 : 2 
        9 : 2 3 
        10 : 2 
        11 : 2 3 4 5 6 7 8 9 10 
        12 : 2 
        13 : 2 3 4 5 6 7 8 9 10 11 12 
        14 : 2 
        15 : 2 3 
*/


#include <stdio.h>


int main(void) {
    int i, j;

    for (i = 3; i <= 15; i++) {
        printf("%d : ", i);

        for (j = 2; j < i; j++) {
            printf("%d ", j);

            if (i % j == 0)
                break;
        }

        putchar('\n');
    }

    return 0;
}