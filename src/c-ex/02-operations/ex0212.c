#include <stdio.h>


int mai(void)
{
    int height;

    printf("input key: ");
    scanf("%d", &height);

    printf("%.1f\n", (height - 100) * 0.9);

    return 0;
}