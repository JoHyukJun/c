/*
    - 다음은 p 가 가리키는 구조체 xyz 형 객체의 (1) 인 x, y, z 에 0을 대입하는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
} a, b;

void set0(struct xyz *p) {
    p->x = 0;
    p->y = 0;
    p->z = 0;
}

int main(void) {
    struct xyz a = {5, 3, 1.1};

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    set0(&a);

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}