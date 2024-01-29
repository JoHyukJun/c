/*
    - 다음은 p 가 가리키는 XYZ 형 객체의 (1) 인 x, y, z에 0 을 대입한는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>


typedef struct {
    int x;
    long y;
    double z;
} XYZ;


void set0(XYZ *p) {
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

int main(void) {
    XYZ a = {5, 3, 1.1};

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    set0(&a);

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}