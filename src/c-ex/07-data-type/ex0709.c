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

unsigned lsht(unsigned x, int n) {
    return (n <= 0 || n >= int_bits()) ? x : (x << n);
}

unsigned set(unsigned x, int pos) {
    return x | lsht(1U, pos);
}

unsigned reset(unsigned x, int pos) {
    return x & ~lsht(1U, pos);
}

unsigned inverse(unsigned x, int pos) {
    return x ^ lsht(1U, pos);
}

int main(void) {
    unsigned  x, pos;

    printf("부호 없는 정수 x 를 n 비트 회전합니다.\n");
    printf("x: "); scanf("%u", &x);
    printf("pos: "); scanf("%u", &pos);

    printf("\nx                 : "); print_bits(x);
    printf("\nset(x, pos)       : "); print_bits(set(x, pos));
    printf("\nreset(x, pos)     : "); print_bits(reset(x, pos));
    printf("\ninverse(x, pos)   : "); print_bits(inverse(x, pos));
    putchar('\n');

    return 0;
}