/*
    - 다음은 int 형 가인수 a 와 b 의 합과 차이를 sum 이 가리키는 변수와 diff 가 가리키는 변수에 저장하는 함수다.
*/


#include <stdio.h>


void sum_diff(int a, int b, int *sum, int *diff) {
    *sum = a + b;
    *diff = a > b ? a - b : b - a;
}

int main(void) {
    int sum = 0;
    int diff = 0;

    printf("sum: %d diff: %d\n", sum, diff);

    sum_diff(5, 4, &sum, &diff);

    printf("sum: %d diff: %d\n", sum, diff);

    return 0;
}