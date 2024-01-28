/*
    - 다음은 (1) 인 x, y, z 의 값이 모두 0 인 구조체 xyz (의 값) 를 그대로 반환하는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
} a, b;


struct xyz xyz0(void) {
    struct xyz t = {0, 0, 0.0};

    return t;
}

int main(void) {
    struct xyz a;

    a = xyz0();

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}