/*
    - 앞의 프로그램에서 double형을 감싼 ()는 (71) 연산자다. 덧붙쳐 다음과 같이 해도 된다.
    - (71): 캐스트
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

    printf("%d %d avg %f\n", x, y, (x + y) / 2.0);
    
    return 0;
}