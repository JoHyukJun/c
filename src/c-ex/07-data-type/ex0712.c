#include <stdio.h>
#include <limits.h>


int main(void) {
    unsigned a, b;

    puts("부호 없는 정숫값의 합과 곱을 구합니다.");
    printf("UINT_MAX는 %u 입니다.\n", UINT_MAX);
    printf("UINT_MAX를 넘는다면 그 연산 결과는 (UINT_MAX + 1) 로 나눈 나머지가 된다.\n");
    printf("a: "); scanf("%u", &a);
    printf("b: "); scanf("%u", &b);

    printf("a + b = %u\n", a + b);
    printf("a * b = %u\n", a * b);

    return 0;
}