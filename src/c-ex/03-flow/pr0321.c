/*
    - 다음은 int 형 번수 a, b, c 의 값이 모두 다르면 그렇다고 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int a, b, c;

    puts("input 3 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    if (a != b && b != c && a != c)
        puts("3 numbers diff.");

    return 0;
}