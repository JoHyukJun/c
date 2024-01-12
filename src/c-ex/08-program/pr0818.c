/*
    - 다음은 int 형 두 값 x 와 y 의 값을 교환하는 (1) 매크로다.
    - (1): 함수 형식
*/


#include <stdio.h>

#define swap_int(x, y) do { int t = x; x = y; y = t; } while(0)

int main(void) {
    int a = 3;
    int b = 4;

    swap_int(a, b);
    
    printf("swap_int(a, b):a:%d:b:%d\n", a, b);

    return 0;
}