/*
    - 다음은 모두 전달받은 x, y 중 큰 값을 구해 반환하는 함수다.
*/


#include <stdio.h>


int max2(int x, int y) {
    return (x > y) ? x : y;
}

int max2_1(int x, int y) {
    int max;

    if (x > y) {
        max = x;
    }
    else {
        max = y;
    }

    return max;
}

int max2_2(int x, int y) {
    if (x > y) {
        return x;
    }
    else {
        return y;
    }
}

int max2_3(int x, int y) {
    int max = x;

    if (y > x) {
        max = y;
    }

    return max;
}

int main(void) {
    printf("max2(1, 4): %d\n", max2(1, 4));
    printf("max2(4, 1): %d\n", max2(4, 1));

    printf("max2_1(1, 4): %d\n", max2_1(1, 4));
    printf("max2_1(4, 1): %d\n", max2_1(4, 1));

    printf("max2_2(1, 4): %d\n", max2_2(1, 4));
    printf("max2_2(4, 1): %d\n", max2_2(4, 1));

    printf("max2_3(1, 4): %d\n", max2_3(1, 4));
    printf("max2_3(4, 1): %d\n", max2_3(4, 1));

    return 0;
}