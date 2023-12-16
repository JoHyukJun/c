/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        3 32 41 50 6
*/


#include <stdio.h>


int main(void) {
    int y = 3;
    int z = 3;

    while (y >= 0)
        printf("%d %d", y--, z++);

    return 0;
}