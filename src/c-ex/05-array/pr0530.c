/*
    - 다음은 2행 3열의 행렬을 나타내는 2차원 배열 mx 에서 my 를 뺀 값을 mz 로 저장해 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int i, j;
    int mx[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int my[2][3] = {{6, 3, 4}, {5, 1, 2}};
    int mz[2][3];

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            mz[i][j] = mx[i][j] - my[i][j];

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            printf("%3d", mz[i][j]);
        putchar('\n');

    return 0;
}