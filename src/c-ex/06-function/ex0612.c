#include <stdio.h>

#define NUMBER 7


void intary_rcpy(int v1[], int v2[], int n) {
    int i;

    for (i = 0; i < n / 2; i++) {
        v1[i] = v2[n - i - 1];
    }
}

int main(void) {
    int i;
    int x1[NUMBER], x2[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("x1[%d]: ", i);
        scanf("%d", &x1[i]);
    }

    intary_rcpy(x1, x2, NUMBER);

    puts("intary_rcpy");
    for (i = 0; i < NUMBER; i++) {
        printf("x2[%d]: %d\n", i, x2[i]);
    }
    
    return 0;
}