/*
    - 다음은 변수 a, b, c 의 중앙값(예를 들어 2, 3, 1 의 중앙값은 2 이고 1, 2, 1 읭 중앙값은 1 이면 3, 3, 3 의 중앙값은 3)을 med 에 대입하는 프로그램의 일부다.
    - 변수명 med 는 중앙값이라는 median 에서 유래한 것이다.
*/


#include <stdio.h>


int main(void) {
    int a, b, c, med;

    puts("input 3 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    if (a >= b)
        if (b >= c)
            med = b;
        else if (a <= c)
            med = a;
        else
            med = c;
    else if (a > c)
        med = a;
    else if (b > c)
        med = c;
    else
        med = b;

    printf("med: %d\n", med);

    return 0;
}