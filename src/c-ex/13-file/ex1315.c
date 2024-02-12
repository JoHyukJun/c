#include <stdio.h>
#include <time.h>


int main(void) {
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);
    char *wday_name[] = {"일", "월", "화", "수", "목", "금", "토"};

    printf("지금의 날짜와 시각은 %d년 %d월 %d일(%s) %d시 %d분 %d초 입니다.\n",
    timer->tm_year + 1900,
    timer->tm_mon + 1,
    timer->tm_mday,
    wday_name[timer->tm_wday],
    timer->tm_hour,
    timer->tm_min,
    timer->tm_sec);

    return 0;
}