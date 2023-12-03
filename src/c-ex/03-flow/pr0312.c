/*
    - 다음은 n값이 5로 나눠떨어지는지 판정해서 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;

    puts("input 1 number.");
    printf("n: ");
    scanf("%d", &n);

    if (n % 5)
        puts("invalid");
    else
        puts("valid");

    return 0;
}