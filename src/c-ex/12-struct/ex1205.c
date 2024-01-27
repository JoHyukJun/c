#include <stdio.h>
#include <math.h>

#define sqr(n) ((n) * (n))


typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point pt;
    double fuel;
} Car;


double distance_of(Point pa, Point pb) {
    return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

void put_info(Car c) {
    printf("현재 위치: (%.2f, %.2f)\n", c.pt.x, c.pt.y);
    printf("남은 연료: %.2f리터\n", c.fuel);
}

int move(Car *c, Point dest) {
    double d = distance_of(c->pt, dest);

    if (d > c->fuel) {
        return 0;
    }

    c->pt = dest;
    c->fuel -= d;

    return 1;
}

int main(void) {
    Car mycar = {{0.0, 0.0}, 90.0};

    while (1) {
        int select;
        Point dest;
        double x, y;

        put_info(mycar);

        printf("이동할까요? [1...이동할 곳 좌표 입력 / 2...이동 거리 입력 / 0...종료]: ");
        scanf("%d", &select);

        if (select == 0) break;

        switch (select)
        {
        case 1:
            printf("목적지 x 좌표: "); scanf("%lf", &dest.x);
            printf("목적지 y 좌표: "); scanf("%lf", &dest.y);
            break;
        case 2:
            printf("X 방향 이동 거리: "); scanf("%lf", &x);
            printf("Y 방향 이동 거리: "); scanf("%lf", &y);
            dest.x = mycar.pt.x + x;
            dest.y = mycar.pt.y + y;
            break;
        }

        if (!move(&mycar, dest)) {
            puts("\a연료 부족으로 이동할 수 없습니다.");
        }
    }

    return 0;
}