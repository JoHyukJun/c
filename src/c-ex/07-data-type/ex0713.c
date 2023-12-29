#include <stdio.h>


int main(void) {
    float a;
    double b;
    long double c;

    puts("3개의 실숫값을 입력해주세요.");
    printf("float: "); scanf("%f", &a);
    printf("double: "); scanf("%lf", &b);
    printf("long double: "); scanf("%Lf", &c);

    printf("a = %f\n", a);
    printf("b = %f\n", b);
    printf("c = %Lf\n", c);

    return 0;
}