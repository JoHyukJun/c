#include <stdio.h>


int main(void)
{
    int a, b;
    int no, lower, upper;
    int sum = 0;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    if (a > b) {
        lower = b;
        upper = a;
    }
    else {
        lower = a;
        upper = b;
    }

    no = lower;

    do {
        sum = sum + no;
        no = no + 1;
    } while (no <= upper);

    printf("sum: %d\n", sum);

    return 0;
}