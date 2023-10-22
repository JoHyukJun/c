#include <stdio.h>


int main(void) {
    // point 1
    int n1, n2;
    int c = 3;
    int t;
    // end of point 1

    puts("input 2 number");
    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);

    t = 2 * c * (n1 + n2);

    printf("2 * c * (n1 + n2) = %d\n", t);

    return 0;
}