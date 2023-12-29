#include <stdio.h>
#include <math.h>


int main(void) {
    int i;
    double x = 0.0;

    for (i = 0; i <= 1000000; i++) {
        printf("x = %f x = %f\n", x, i / 1000000.0);
        x += 0.000001;
    }

    return 0;
}