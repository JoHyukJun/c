#include <stdio.h>


int main(void)
{
    int height;
    int lower, upper, step;

    printf("lower: ");
    scanf("%d", &lower);
    printf("upper: ");
    scanf("%d", &upper);
    printf("step: ");
    scanf("%d", &step);

    for (height = lower; height <= upper; height += step)
        printf("%dcm %.2fkg\n", height, (height - 100) * 0.9);

    return 0;
}