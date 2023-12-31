/*
    - 다음은 전달받은 unsigned char 형 값을 구성하는 비트 중 0인 비트의 개수를 구해 반환하는 함수다.
*/


#include <stdio.h>
#include <limits.h>


int count0bits(unsigned char x) {
    int i;
    int bits = 0;

    for (i = 0; i < CHAR_BIT; i++) {
        if ((x & i) == 0)
            bits++;
        x >>= 1;
    }

    return bits;
}

void print_bits(unsigned char x) {
    int i;

    for (i = CHAR_BIT - 1; i >= 0; i--)
        putchar(((x >> i) & 1U) ? '1' : '0');
}

int main(void) {
    unsigned char x;

    printf("x: "); scanf("%s", &x);


    printf("\nx                 : "); print_bits(x);
    printf("\ncount0bits(x)     : %d", count0bits(x));
    putchar('\n');

    return 0;
}