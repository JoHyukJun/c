#include <stdio.h>


int sumup(int n) {
    int i;
    int sum = 0;

    for (i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int main(void) {
    int n;

    printf("n: "); scanf("%d", &n);

    printf("sum val: %d\n", sumup(n));

    return 0;
}