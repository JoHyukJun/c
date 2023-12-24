/*
    - 다음은 n 행 n 열의 2차원 배열 m 의 모든 구성 요소에 0을 대입하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int n = 2;
    int i, j;
    int m[n][n];

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;

    return 0;
}