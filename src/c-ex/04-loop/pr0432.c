/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        123
        1234
        12345
        123456
        1234567
*/


#include <stdio.h>


int main(void) {
    int i, j;

    for (i = 3; i <= 7; i++) {
        for (j = 1; j <= i; j++)
            printf("%d", j);
        putchar('\n');
    }
    
    return 0;
}