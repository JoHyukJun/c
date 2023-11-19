/*
    - 다음은 정숫값 2개를 읽어 들여 이들 값을 사칙연산한 값을 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int x, y;

    puts("input 2 number");
    printf("x: ");
    scanf("%d" &x);
    printf("y: ");
    scanf("%d", &y);

    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);

    return 0;
}