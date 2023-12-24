#include <stdio.h>

#define NUMBER 7


void rev_intary(int v[], int n) {
    int i;

    for (i = 0; i < n / 2; i++) {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

int main(void) {
    int i;
    int x[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    rev_intary(x, NUMBER);

    puts("rev_intary");
    for (i = 0; i < NUMBER; i++) {
        printf("x[%d]: %d\n", i, x[i]);
    }
    
    return 0;
}