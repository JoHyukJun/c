/*
    - 다음 프로그램 중 잘못된 곳을 찾아라.
*/


#include <stdio.h>
/*
    - limit.h
    -> limits.h
*/
#include <limits.h>


int main(void) {
    /*
        - UCHAR_MIN
        -> 0
    */
    printf("unsigned char 의 표현 범위: %u~%u\n", 0, UCHAR_MAX);
    /*
        - UINT_MIN
        -> 0
    */
    printf("unsigned char 의 표현 범위: %u~%u\n", 0, UINT_MAX);

    return 0;
}