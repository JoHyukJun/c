/*
    - 다음은 XYZ 형 구조체형인 *x 와 *y 의 모든 (1) 값이 같으면 1을 반환하고 그렇지 않으면 0을 반환하는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>


typedef struct {
    int x;
    long y;
    double z;
} XYZ;


int XYZeq(const XYZ *x, const XYZ *y) {
    if (x->x != y->x) return 0;
    if (x->y != y->y) return 0;
    if (x->z != y->z) return 0;

    return 1;
}

void set0(XYZ *p) {
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

int main(void) {
    XYZ a = {5, 3, 1.1};
    XYZ b = {4, 2, 0.1};

    printf("XYZeq(a, b) = %d\n", XYZeq(&a, &b));

    set0(&a);
    set0(&b);

    printf("XYZeq(a, b) = %d\n", XYZeq(&a, &b));

    return 0;
}