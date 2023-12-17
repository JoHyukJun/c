/*
    - 다음 프로그램 일부에서 잘못된 곳을 찾아라.
*/


#include <stdio.h>


int main(void) {
    int i;
    /*
        - size err
    */
    int a[5] = {0, 1, 2, 3, 4};

    /*
        - size err
    */
    for (i = 0; i < 5; i++) {
        /*
            - val err
        */
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}