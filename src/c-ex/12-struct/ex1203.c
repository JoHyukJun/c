#include <stdio.h>


struct xyz {
    int x;
    long y;
    double z;
};


struct xyz scan_xyz() {
    struct xyz temp;
    
    printf("int형 멤버 x 의 값: "); scanf("%d", &temp.x);
    printf("long형 멤버 y 의 값: "); scanf("%ld", &temp.y);
    printf("double형 멤버 z 의 값: "); scanf("%lf", &temp.z);

    return temp;
}

int main(void) {
    struct xyz s;

    s = scan_xyz();

    printf("s.x = %d\n", s.x);
    printf("s.y = %ld\n", s.y);
    printf("s.z = %f\n", s.z);

    return 0;
}