#include <stdio.h>


int main(void) {
    float x, sum = 0.0;

    for (x = 0.0; x <= 1.0; x += 0.01)
        sum += x;

    printf("sum: %f\n", sum);

    int i;
    sum = 0.0;

    for (i = 0; i <= 100; i++)
        sum += i / 100.0;

    printf("sum: %f\n", sum);

    return 0;
}