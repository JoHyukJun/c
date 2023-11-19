/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    - 실행결과:
    1234
    1234
    01234
    234
     1234
    1234
    01234
    1234
    1234 
    12.340000
    12
    12.3
    12.34
     12.3
      12.3
       12.3
*/


#include <stdio.h>


int main(void) {
    printf("%d\n", 1234);
    printf("%.3d\n", 1234);
    printf("%.5d\n", 1234);
    printf("%3d\n", 1234);
    printf("%5d\n", 1234);
    printf("%03d\n", 1234);
    printf("%05d\n", 1234);
    printf("%-3d\n", 1234);
    printf("%-5d\n", 1234);

    printf("%f\n", 12.34);
    printf("%.0f\n", 12.34);
    printf("%.1f\n", 12.34);
    printf("%.2f\n", 12.34);
    printf("%5.1f\n", 12.34);
    printf("%6.1f\n", 12.34);
    printf("%7.1f\n", 12.34);

    return 0;
}