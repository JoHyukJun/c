#include <stdio.h>
#include <stdlib.h>

extern int addnum(int a, int b);


int main(int argc, char* argv[]) {
    int i, a, b, sum;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    sum = addnum(a, b);

    printf("Sum %d ~ %d = %d\n", a, b, sum);
}