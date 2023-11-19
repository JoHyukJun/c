/*
    - 다음은 double 형 변수 r로 원의 반지름을 읽어 들여 넓이를 소수점 세 자리까지 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    double r;

    printf("r: ");
    scanf("%lf", &r);

    printf("size %.3f\n", 3.14 * r);

    return 0;
}