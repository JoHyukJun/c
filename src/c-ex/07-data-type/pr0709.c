/*
    - 다음은 정수 n1 부터 n2 까지의 값을 8진수, 10진수, 16진수로 출력하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int i, n1 = 77, n2 = 80;

    for (i = n1; i < n2; i++) {
        printf("%o %d %X\n", i ,i ,i);
    }
    return 0;
}