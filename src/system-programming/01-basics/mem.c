#include <stdio.h>
#include <stdlib.h>


int main() {
    int *ptr;

    ptr = malloc(sizeof(int) * 200);

    printf("size of ptr = %d", _msize(ptr));

    free(ptr);
}