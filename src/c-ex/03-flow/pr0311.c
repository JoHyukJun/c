/*
    - 다음은 a가 b의 약수인지 판정해서 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    if (b % a)
        puts("invalid");
    else
        puts("valid");

    return 0;
}