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

unsigned rrotate(unsigned x, int n) {
    unsigned lrotate(unsigned, int);

    if (n < 0)
        lrotate(x, -n);
    else {
        int bits = int_bits();
        n %= bits;

        return n ? (x >> n) | (x << (bits - n)) : x;
    }
}

unsigned lrotate(unsigned x, int n) {
    if (n < 0)
        rrotate(x, -n);
    else {
        int bits = int_bits();
        n %= bits;

        return n ? (x << n) | (x >> (bits - n)) : x;
    }
}

int main(void) {
    unsigned  x, n;

    printf("부호 없는 정수 x 를 n 비트 회전합니다.\n");
    printf("x: "); scanf("%u", &x);
    printf("n: "); scanf("%u", &n);

    printf("\n회전하기 전   : "); print_bits(x);
    printf("\n오른쪽 회전   : "); print_bits(rrotate(x, n));
    printf("\n왼쪽 회전     : "); print_bits(lrotate(x, n));
    putchar('\n');

    return 0;
}