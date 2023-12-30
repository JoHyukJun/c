/*
    - 앞 문제의 함수 print16bits 를 호출하는 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        0000000000000000
        0000000000000001
        1111111111111111
        1111111111111110
        0000000010100000
        0000000011111010
        0000000001011010
        0000000010101010
        0000000010101010
        0000000101010100
        0000000001010101
        0000001010101000
        0000000000101010
        1111111111111000
*/


#include <stdio.h>


void print16bits(unsigned x) {
    int i;

    for (i = 15; i >=0; i--)
        putchar(((x >> i) & 1U) ? '1': '0');
    putchar('\n');
}

int main(void) {
    int i;

    print16bits(0);
    print16bits(1);
    print16bits(~0);
    print16bits(~1);
    print16bits(170 & 240);
    print16bits(170 | 240);
    print16bits(170 ^ 240);

    for (i = 0; i < 3; i++)
    {
        print16bits(170 << i);
        print16bits(170 >> i);
    }

    print16bits(~0 << 3);
    
    return 0;
}