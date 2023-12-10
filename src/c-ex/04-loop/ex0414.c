#include <stdio.h>


int main(void)
{
    int i;
    int sum = 0;
    int n;

    printf("n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        sum += 1;

    printf("sum: %d\n", sum);

    return 0;
}