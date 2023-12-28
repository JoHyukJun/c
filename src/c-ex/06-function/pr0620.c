/*
    - 다음은 3행 4열 2차원 배열 v 의 모든 요소에 0 을 대입하는 함수다.
    - 이때 v 의 선언에서 [3] 안의 3 은 (1). 또한 [4] 안의 4는 (2).
    - (1): 생략할 수 있다
    - (2): 생략할 수 없다
*/


#include <stdio.h>


void ary34_set0(int v[3][4]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            v[i][j] = 0;
        }
    }
}

int main(void) {
    int i, j;
    int a[3][4];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("a[%d][%d]: %d\n", i, j, a[i][j]);
        }
    }

    ary34_set0(a);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("a[%d][%d]: %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}