/*
    - 다음은 a 와 b 중 작은 쪽의 값과 큰 쪽의 값을 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("min: %d \n", (a < b) ? a : b);
    printf("max: %d \n", (a > b) ? a : b);

    return 0;
}