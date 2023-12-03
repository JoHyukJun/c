/*
    - 다음은 n의 절댓값을 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;

    puts("input 1 number.");
    printf("n: ");
    scanf("%d", &n);

    printf("abs: %d\n", n >= 0 ? n : -n);

    return 0;
}