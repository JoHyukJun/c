#include <stdio.h>

extern int subnum(int a, int b);


int main() {
    int res;

    res = subnum(1, 10);
    printf("subnum result = %d\n", res);
}