#include <stdio.h>
#include <limits.h>


int main(void) {
    puts("이 환경에서의 각 정수형 값의 범위");
    printf("signed short int    :   %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("signed int          :   %d ~ %d\n", INT_MIN, INT_MAX);
    printf("signed long int     :   %ld ~ %ld\n", LONG_MIN, LONG_MAX);

    printf("unsigned short int  :   %u ~ %u\n", 0, USHRT_MAX);
    printf("unsigned int        :   %u ~ %u\n", 0, UINT_MAX);
    printf("unsigned long int   :   %lu ~ %lu\n", 0, ULONG_MAX);

    return 0;
}