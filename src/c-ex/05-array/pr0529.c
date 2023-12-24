/*
    - 다음 프로그램에서 잘못된 부분을 찾아라.
*/


#include <stdio.h>

/*
    - #define
*/
#define MAX 10

int main(void) {
    double a[MAX];

    for (i = 0; i < MAX; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}