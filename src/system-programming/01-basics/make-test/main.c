#include <stdio.h>

extern int addnum(int a, int b);


int main() {
    int sum;

    sum = addnum(1, 10);
    printf("Sum 1~10 = %d\n", sum);
}