/*
    - 다음은 int형 변수 a의 값이 int형 병수 b의 몇 퍼센트인지 출력하는 프로그램이다. 여기서 소수점 이하는 버린다.
*/


#include <stdio.h>


int main(void) {
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("%d\n", 100 * a / b);

    return 0;
}