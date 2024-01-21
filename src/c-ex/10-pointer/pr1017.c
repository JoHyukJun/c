/*
    - 요소 개수가 10 이고 요소형이 int 인 배열 x 가 있다고 할 때 앞 문제의 set0 함수를 set0((1)) 라 호출하면 x[2] 에 0 이 대입된다.
    - (1): &x[2]
*/


#include <stdio.h>


void set0(int v[]) {
    v[0] = 0;
}

int main(void) {
    int x[] = {13, 3, 4};

    printf("x[0]: %d\n", x[2]);

    set0(&x[2]);

    printf("x[2]: %d\n", x[2]);

    return 0;
}