#include <stdio.h>


int sqr(int x) {
    return x * x;
}

int pow4(int x) {
    return sqr(x) * sqr(x);
}

int main(void) {
    int n;

    printf("n: "); scanf("%d", &n);

    printf("pow val: %d\n", pow4(n));

    return 0;
}