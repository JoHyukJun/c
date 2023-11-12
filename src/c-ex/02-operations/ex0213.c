#include <stdio.h>


int main(void)
{
    double height, weight;

    printf("height: ");
    scanf("%lf", &height);
    printf("weight: ");
    scanf("%lf", &weight);

    printf("BMI = %.2f\n", weight / ((height / 100.0) * (height / 100.0)));

    return 0;
}