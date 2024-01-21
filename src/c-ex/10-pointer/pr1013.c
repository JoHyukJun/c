/*
    - 다음은 int 형 변수 n 과 double 형 변수 x 의 주소를 출력하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;
    double x;

    printf("n 의 주소: %p\n", &n);
    printf("x 의 주소: %p\n", &x);

    return 0;
}