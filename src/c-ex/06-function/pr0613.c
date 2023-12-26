/*
    - 다음은 전달받은 정수 2개의 합을 구해 반환하는 함수다.
*/


#include <stdio.h>


int sum_of(int a, int b) {
    return (a + b);
}

int main(void) {
    printf("sum_of(1, 2): %d\n", sum_of(1, 2));
    
    return 0;
}