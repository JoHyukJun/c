/*
    - 다음은 x 의 제 n 비트를 0 또는 1로 하여 반환하는 함수다.
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

unsigned Bitof(unsigned *x, int n) {
    return (*x >> n) & 1;
}

int main(void) {
    unsigned  x;
    int n;

    printf("x: "); scanf("%u", &x);
    printf("n: "); scanf("%d", &n);

    printf("\nx                 : "); print_bits(x);
    printf("\nBitof(x, n)       : "); print_bits(Bitof(&x, n));
    putchar('\n');

    return 0;
}