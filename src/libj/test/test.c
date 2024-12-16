#include <stdio.h>
#include "test.h"


void print_test()
{
    printf("test\n");
}

int main()
{
    int t1;

    print_test();

    t1 = sem_create(TEST_SEM_KEY);

    while(1)
    {
        printf("t1: %d\n", t1);

        sem_lock(t1);

        printf("lock\n");

        t1 = sem_create(TEST_SEM_KEY); 

        sem_unlock(t1);

        printf("unlock\n");
    }

    return (0);
}