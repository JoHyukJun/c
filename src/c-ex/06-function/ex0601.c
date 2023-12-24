#include <stdio.h>


int min2(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    int n1, n2;

    puts("input 2 number.");
    printf("n1: "); scanf("%d", &n1);
    printf("n2: "); scanf("%d", &n2);

    printf("min val: %d\n", min2(n1, n2));

    return 0;
}