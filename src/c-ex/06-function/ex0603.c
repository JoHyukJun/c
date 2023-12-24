#include <stdio.h>


int cube(int x) {
    return x * x * x;
}

int main(void) {
    int n;

    printf("n: "); scanf("%d", &n);

    printf("cube val: %d\n", cube(n));

    return 0;
}