/*
    - 다음은 X 좌표와 Y 좌표로 구성되는 Point 형 구조체와 왼쪽 위, 오른쪽 아래 Point 형 좌표로 구성되는 Rectangle 형 구조체를 이용해서 직사각형의 넓이와 주위 길이(네 변의 길이 합계) 를 구하고 출력하는 프로그램이다.
*/


#include <stdio.h>

#define abs(n) ((n >= 0) ? (n) : -(n))


typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Rectangle;


Point scan_point(void) {
    Point temp;
    
    printf("X: "); scanf("%lf", &temp.x);
    printf("Y: "); scanf("%lf", &temp.y);

    return temp;
}

double area_of(Rectangle r) {
    return abs(r.p2.x - r.p1.x) * abs(r.p2.y - r.p1.y);
}

double circumference_of(const Rectangle *r) {
    return 2 * (abs(r->p2.x - r->p1.x) + abs(r->p2.y - r->p1.y));
}

int main(void) {
    Rectangle r;

    puts("input point: ");
    puts("point1.");
    r.p1 = scan_point();
    puts("point2.");
    r.p2 = scan_point();

    printf("area = %f\n", area_of(r));
    printf("circumference = %f\n", circumference_of(&r));

    return 0;
}