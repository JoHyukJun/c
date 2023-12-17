/*
    - 다음은 요소 개수가 5인 double 형 배열 a 의 모든 요소 합계를 변수 sum 에 저장하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    double a[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double sum = 0;

    for (i = 0; i < 5; i++)
        sum += a[i];

    return 0;
}