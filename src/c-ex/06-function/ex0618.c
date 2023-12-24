#include <stdio.h>


void put_count(void) {
    static int count = 0;
    printf("put_count: %d\n", ++count);
}

int main(void) {
    int i, n;

    printf("call: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        put_count();
    }

    return 0;
}