#include <stdio.h>


int main(void) {
    int n;

    printf("input number: ");
    scanf("%d", &n);

    printf("n + 10 = %d\n", n + 10);
    printf("n - 10 = %d\n", n - 10);
    printf("n * 10 = %d\n", n * 10);
    printf("n / 10 = %d\n", n / 10);
    printf("n % 10 = %d\n", n % 10);

    return 0;
}