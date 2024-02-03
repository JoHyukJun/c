/*
    - 다음은 XYZ 형 구조체 배열 a 의 요소를 (1) 인 x 의 오름차순으로 정렬하는 함수다.
    - (1): 멤버 변수
*/


#include <stdio.h>

#define NUMBER 5


typedef struct {
    int x;
    long y;
    double z;
} XYZ;


void swap_XYZ(XYZ *x, XYZ *y) {
    XYZ temp = *x;
    *x = *y;
    *y = temp;
}

void sort_by_x(XYZ x[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (x[j - 1].x > x[j].x) {
                swap_XYZ(&x[j - 1], &x[j]);
            }
        }
    }
}

int main(void) {
    int i;
    XYZ x[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("x: "); scanf("%d", &x[i].x);
        printf("y: "); scanf("%ld", &x[i].y);
        printf("z: "); scanf("%lf", &x[i].z);
    }

    for (i = 0; i < NUMBER; i++) {
        printf("%-8d %6ld%6.1lf\n", x[i].x, x[i].y, x[i].z);
    }

    sort_by_x(x, NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("%-8d %6ld%6.1f\n", x[i].x, x[i].y, x[i].z);
    }

    return 0;
}