/*
    - 다음은 x 의 모든 비트를 반전한 값을 반환하는 함수다.
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

unsigned rev_of(unsigned x) {
    return ~x;
}

int main(void) {
    unsigned  x;

    printf("x: "); scanf("%u", &x);

    printf("\nx                 : "); print_bits(x);
    printf("\nrev_of(x)         : "); print_bits(rev_of(x));
    putchar('\n');

    return 0;
}