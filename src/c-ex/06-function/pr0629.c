/*
    - 다음은 n 행 3열 2차원 배열 a 의 모든 구성 요소 합계를 구해 반환하는 함수다. 
*/


#include <stdio.h>

#define NUMBER 5


int sum_ary2D(const int a[][3], int n) {
    int i, j;
    int sum = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
            sum += a[i][j];

    return sum;
}

int main(void) {
    int i;
    int a[NUMBER][3] = {{3, 4, 5}, {3, -4, -5}, {7, 4, 5}, {3, 4, 5}, {-3, -4, 2}};

    printf("sum_ary2D(a, NUMBER): %d\n" , sum_ary2D(a, NUMBER));

    return 0;
}