/*
    - 다음은 m값이 3, 4, 5 중 하나면 "봄입니다." 를 출력하고 그렇지 않으면 "봄이 아닙니다." 를 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int m;

    puts("input 1 number.");
    printf("m: ");
    scanf("%d", &m);

    if (m == 3 || m == 4 || m == 5)
        puts("봄입니다.");
    else
        puts("봄이 아닙니다.");

    if (a > 2 && a < 6)
        puts("봄입니다.");
    else
        puts("봄이 아닙니다.");

    return 0;
}