/*
    - 다음은 요소형이 모두 int 형인 배열 v 의 맨 앞 요소에 0 을 대입하는 함수다.
*/


#include <stdio.h>


void set0(int v[]) {
    v[0] = 0;
}

void set0_2(int *v) {
    *v = 0;
}

int main(void) {
    int a[] = {13, 3, 4};

    printf("a[0]: %d\n", a[0]);

    set0(a);

    printf("a[0]: %d\n", a[0]);

    a[0] = 13;

    set0_2(a);

    printf("a[0]: %d\n", a[0]);

    return 0;
}