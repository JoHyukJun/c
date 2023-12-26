/*
    - 다음은  x 의 n 제곱을 구해 반환하는 함수다.
*/


#include <stdio.h>


double power(double x, int n) {
    int i;
    double tmp = x;

    for (i = 1; i < n; i++)
        tmp *= x;

    return tmp;
}

double power2(double x, int n) {
    double tmp = x; 

    while(n-- > 1) {
        tmp *= x;
    }

    return tmp;
}

int main(void) {
    printf("power(3, 3): %lf\n", power(3, 3));
    printf("power2(3, 3): %lf\n", power2(3, 3));

    return 0;
}