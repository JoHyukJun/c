/*
    - 다음은 앞 문제의 함수 max2 를 이용하여 전달받은 a, b, c, d 중 최댓값을 구해 반환하는 함수다.
*/


#include <stdio.h>


int max2(int x, int y) {
    return (x > y) ? x : y;
}

int max4(int a, int b, int c, int d) {
    return max2(max2(a, b), max2(c, d));
}

int main(void) {
    printf("max4(1, 2, 3, 4): %d\n", max4(1, 2, 3, 4));

    return 0;
}