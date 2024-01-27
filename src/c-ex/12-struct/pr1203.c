/*
    - 다음은 구조체 xyz 형 객체 a 의 (1) 인 x, y, z 에 각각 1, 2, 3.14 를 대입하는 프로그램 일부다.
    - (1): 멤버 변수
*/


#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
} a, b;


int main(void) {
    struct xyz a;

    a.x = 1;
    a.y = 2;
    a.z = 3.14;

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}