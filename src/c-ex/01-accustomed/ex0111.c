#include <stdio.h>


int main(void) {
    int n1, n2;
    int dup;

    puts("input two int");
    printf("n1: ");
    scanf("%d", &n1);
    scanf("%d", &n2);

    dup = n1 * n2;

    printf("res: %d\n", dup);

    return 0;
}