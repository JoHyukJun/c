/*
    - 다음은 실행 결과와 같이 정숫값이나 실숫값을 정해진 형식으로 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    printf("[%d]\n", 1234);
    printf("[%06d]\n", 1234);
    printf("[%6d]\n", 1234);
    printf("[%-5d]\n", 1234);

    printf("[%f]\n", 123.45);
    printf("[%6.2f]\n", 123.45);
    printf("[%7.2f]\n", 123.45);

    return 0;
}