#include <stdio.h>


int main(void) {
    int n;

    printf("n: "); scanf("%d", &n);

    printf("8진수는 0%o입니다.\n", n);
    printf("16진수는 0x%x입니다.\n", n);

    return 0;
}