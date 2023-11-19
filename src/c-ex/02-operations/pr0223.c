/*
    - 다음은 실숫값 2개를 변수 x와 y로 읽어 들여 그 평균을 정숫값으로 출력하고자 하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    double x, y;

    puts("input 2 floating number.");
    printf("x: ");
    scanf("%lf", &x);
    printf("y: ");
    scanf("%lf", &y);

    printf("avg = %d\n", (int)((x + y) / 2));

    return 0;
}