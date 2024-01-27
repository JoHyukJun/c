/*
    - p 가 구조체 xyz 형 객체를 가리킨다고 하자.
    - 다음은 p 가 가리키는 객체의 (1) 인 x, y, z 에 각각 1, 2, 3.14 를 대입한느 프로그램 일부다.
*/


#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
} a, b;


int main(void) {
    struct xyz *p;

    p->x = 1;
    p->y = 2;
    p->z = 3.14;

    return 0;
}