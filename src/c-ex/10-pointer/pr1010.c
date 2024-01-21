/*
    - 다음 프로그램의 실행 결과를 나타내라.
    ->
        값을 변경할 변수[0...x/1...y]: 0
        x = 8
        y = 7
    ->
        값을 변경할 변수[0...x/1...y]: 1
        x = 5
        y = 8
*/


#include <stdio.h>


int main(void) {
    int sw, x = 5, y =7;
    int *ptr;

    printf("값을 변경할 변수[0...x/1...y]: ");
    scanf("%d", &sw);

    ptr = (sw == 0) ? &x : &y;
    *ptr = 8;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}