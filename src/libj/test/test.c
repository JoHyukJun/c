#include <stdio.h>
#include "test.h"


void print_test()
{
    printf("test\n");
}

int main()
{
    print_test();

    sem_open(TEST_SEM_KEY);

    return (0);
}