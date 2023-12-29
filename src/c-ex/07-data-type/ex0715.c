#include <stdio.h>
#include <math.h>


int main(void) {
    double area;

    puts("정사각형의 넓이로 한 변의 길이를 구합니다.");
    printf("넓이: ");
    scanf("%lf", &area);

    printf("한 변의 길이는 %f입니다.\n", sqrt(area));

    return 0;
}