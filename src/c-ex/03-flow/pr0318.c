/*
    - 다음은 int형 변수 a, b, c, d 의 최댓값을 구해 max 에 대입하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int a, b, c, d, max;

    puts("input 4 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    printf("d: ");
    scanf("%d", &d);

    max = a;

    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;

    int max1, max2;

    max1 = a > b ? a : b;
    max2 = c > d ? c : d;
    max = max1 > max2 ? max1 : max2;

    return 0;
}