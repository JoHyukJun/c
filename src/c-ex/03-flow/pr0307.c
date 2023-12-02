/*
    - 다음은 a 가 b 의 배수인지 판정해수 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    if (a % b)
        puts("not multiple");
    else
        puts("multiple");

    return 0;
}