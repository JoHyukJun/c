#include <stdio.h>


int factorial(int n) {
    int f = 1;

    while (n > 0)
        f *= n--;
    
    return f;
}

int factorial_recersive(int n) {
    if (n > 0)
        return n * factorial_recersive(n - 1);
    else
        return 1;
}

int main(void) {
    int num;

    printf("Input integer number.");
    scanf("%d", &num);

    printf("num:%d:factorial:%d\n", num, factorial(num));
    printf("num:%d:factorial_recersive:%d\n", num, factorial_recersive(num));

    return 0;
}