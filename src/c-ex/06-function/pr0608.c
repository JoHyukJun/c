/*
    - 다음은 a 와 b 의 평균을 double 형의 실숫값으로 반환하는 함수다.
*/


#include <stdio.h>


double ave_of(int a, int b) {
    return 0.5 * (a + b);
}

int main(void) {
    printf("%lf", ave_of(3, 4));

    return 0;
}