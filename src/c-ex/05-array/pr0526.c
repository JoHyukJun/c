/*
    - 다음은 h 행 w 열의 2차원 배열 b 의 모든 구성 요소를 a 로 복사하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int h = 2;
    int w = 3;
    int i, j;
    int m[h][w];

    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            m[i][j] = (i == j ? 1 : 0);

    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            printf("m[%d][%d]: %d\n", i, j, m[i][j]);

    return 0;
}