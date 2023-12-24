#include <stdio.h>


void put_chars(int ch, int n) {
    while (n-- > 0)
    {
        putchar(ch);
    }
}

void put_chars_ln(int ch, int n) {
    put_chars(ch, n);
    putchar('\n');
}

void alert(int n) {
    put_chars('\a', n);
}

int main(void) {
    int n;

    put_chars_ln('=', 24);
    printf("n: "); scanf("%d", &n);
    put_chars_ln('-', 24);

    alert(n);
    putchar('\n');

    put_chars_ln('=', 24);

    return 0;
}