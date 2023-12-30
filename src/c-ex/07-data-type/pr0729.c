/*
    - 다음은 0, 0.01, 0.02, ... , 1.00 의 101 개 값과 그 제곱근을 출력하는 프로그램 일부다.
*/


#include <stdio.h>
#include <math.h>


int main(void) {
    int i;

    for (i = 0; i <= 100; i++) {
        printf("%4.2f %4.2f\n", (double)i / 100.0, sqrt((double)i / 100.0));
    }
    
    return 0;
}