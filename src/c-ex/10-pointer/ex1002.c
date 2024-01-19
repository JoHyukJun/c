#include <stdio.h>


int is_leap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

int days_of_month(int y, int m) {
    int mdays[][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    };

    return mdays[is_leap(y)][m - 1];
}

void decrement_date(int *y, int *m, int *d) {
    if (*d > 1)
        --*d;
    else {
        if (--*m < 1) {
            --*y;
            *m = 12;
        }

        *d = days_of_month(*y, *m);
    }
}

void increment_date(int *y, int *m, int *d) {
    if (*d < days_of_month(*y, *m))
        ++*d;
    else {
        if (++*m > 12) {
            ++*y;
            *m = 1;
        }

        *d = 1;
    }
}

int main(void) {
    int i, n;
    int y, m, d;

    puts("날짜를 입력해주세요.");
    printf("연: "); scanf("%d", &y);
    printf("월: "); scanf("%d", &m);
    printf("일: "); scanf("%d", &d);

    printf("몇 일 뒤로 할까요: "); scanf("%d", &n);

    for (i = 0; i < n; i++)
        decrement_date(&y, &m, &d);

    printf("%d년 %d월 %d일 이 되었습니다.\n", y, m, d);

    printf("몇 일 앞으로로 할까요: "); scanf("%d", &n);

    for (i = 0; i < n; i++)
        increment_date(&y, &m, &d);

    printf("%d년 %d월 %d일 이 되었습니다.\n", y, m, d);

    return 0;
}