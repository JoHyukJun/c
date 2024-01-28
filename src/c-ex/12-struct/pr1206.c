/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        a.x = 5
        a.y = 0
        a.z = 0.000000
*/


#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
} a, b;


int main(void) {
    struct xyz a, b = {5};

    a = b;

    printf("a.x = %d\n", a.x);
    printf("a.y = %ld\n", a.y);
    printf("a.z = %f\n", a.z);

    return 0;
}