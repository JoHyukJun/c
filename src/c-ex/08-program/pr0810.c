/*
    - 다음은 type 형의 두 값 x 와 y 를 교환하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define swap(type, x, y) do {type t = x; x = y; y = t; } while(0)


int main(void) {
    int a = 3;
    int b = 4;
    int c = 7;
    int d = 8;

    swap(int, a, b);
    printf("swap(int, a, b):a:%d:b:%d\n", a, b);

    swap(int, c, d);
    printf("swap(int, c, d):c:%d:d:%d\n", c, d);

    return 0;
}