/*
    - 다음은 (1) 인 x, y, z 의 값이 모두 0인 XYZ 형 (의 값) 을 그대로 반환하는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>


typedef struct {
    int x;
    long y;
    double z;
} XYZ;


XYZ XYZ0(void) {
    XYZ t = {0, 0, 0.0};

    return t;
}

int main(void) {
    XYZ a;

    a = XYZ0();

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}