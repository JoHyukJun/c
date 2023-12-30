/*
    - 다음은 모든 비트가 0인 부호 없는 정수를 반환하는 함수다.
*/


#include <stdio.h>


int count_bits(unsigned x) {
    int bits = 0;

    while (x) {
        if (x & 1U) bits++;
        x >>= 1;
    }

    return bits;
}

int int_bits(void) {
    return count_bits(~0U);
}

void print_bits(unsigned x) {
    int i;

    for (i = int_bits() - 1; i >= 0; i--)
        putchar(((x >> i) & 1U) ? '1' : '0');
}

unsigned all0(void) {
    return 0U;
}

int main(void) {
    printf("\nall0()         : "); print_bits(all0());
    putchar('\n');

    return 0;
}