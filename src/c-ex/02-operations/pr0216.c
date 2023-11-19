/*
    - 다음은 정숫값 2개를 읽어 들여 그 평균값을 실숫값으로 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int x;
    int y;

    puts("input 2 number.");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    printf("%d %d avg %f\n", x, y, ((double)x + y) / 2);
    
    return 0;
}