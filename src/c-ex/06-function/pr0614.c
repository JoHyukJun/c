/*
    - 다음은 전달받은 정수 2개의 차이를 구해 반환하는 함수다.
*/


#include <stdio.h>


int diff_of(int a, int b) {
    return (a - b > 0) ? a - b : b - a;
}

int main(void) {
    printf("diff_of(1, 2): %d\n", diff_of(1, 2));
    printf("diff_of(2, 1): %d\n", diff_of(2, 1));

    return 0;
}