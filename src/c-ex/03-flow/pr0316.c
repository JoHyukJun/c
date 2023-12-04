/*
    - 다음은 a가 b로 나눠떨어질 때 "a를 b로 나누면 99입니다." 라고 몫을 출력하고, 나눠떨어지지 않을 때 "a는 b로 나누면 99이고 나머지는 99입니다" 라고 몫과 나머지를 출력하는 프로그램의 일부다. (99는 값의 일례다)
*/


#include <stdio.h>


int main(void) {
    int a, b, mod;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    if (a % b)
        printf("a를 b로 나누면 %d 이고 나머지는 %d 입니다.\n", a / b, a % b);
    else
        printf("a를 b로 나누면 %d 입니다.\n", a / b);

    printf("a를 b로 나누면 %d", a / b);

    if (a % b != 0)
        printf(" 이고 나머지는 %d ", a % b);
    printf("입니다.\n");

    mod = a % b;

    printf("a를 b로 나누면 %d", a / b);

    if (mod != 0)
        printf(" 이고 나머지는 %d ", mod);
    printf("입니다.\n");

    return 0;
}