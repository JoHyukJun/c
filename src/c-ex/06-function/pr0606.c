/*
    - 다음은 c 가 0, 1, 2 일 때 각각 'R', 'G', 'B' 라 출력하고 그 외의 값일 때는 아무것도 출력하지 않는 함수다.
*/


#include <stdio.h>


void print_rgb(int c) {
    switch (c)
    {
    case 0:
        putchar('R');
        break;
    case 1:
        putchar('G');
        break;
    case 2:
        putchar('B');
        break;
    default:
        break;
    }
}

int main(void) {
    print_rgb(0);
    print_rgb(1);
    print_rgb(2);
    print_rgb(3);

    return 0;
}