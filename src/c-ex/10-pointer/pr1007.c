/*
    - 다음은 int 에 대한 포인터인 px 와 py 값을 교환하는 프로그램 일부다.
    - 예를 들어 px 가 a 를 가리키고 py 가 b 를 가리키는 상태에서 이 프로그램 일부를 실행하면 px 는 b 를 가리키고 py 는 a 를 가리킨다.
*/


#include <stdio.h>


int main(void) {
    int a = 3, b = 4;
    int *px, *py;
    int *pt;

    px = &a;
    py = &b;

    printf("px: %d py: %d\n", *px, *py);

    pt = px;
    px = py;
    py = pt;

    printf("px: %d py: %d\n", *px, *py);

    return 0;
}