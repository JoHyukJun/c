#include <stdio.h>
#include "test.h"


void print_test()
{
    printf("test\n");
}

int main()
{
    int t1, t2;

    print_test();

    t2 = sem_create(TEST_SEM_KEY);
    t1 = sem_open(TEST_SEM_KEY);

    printf("t1: %d\n", t1);
    printf("t2: %d\n", t2);

    return (0);
}