#include <time.h>
#include <stdio.h>


/*
    - char *asctime(const struct tm *tm);
        - asctime() 함수는 tm 구조체로 분해된 시간을 인자로 받고 문자열로 리턴
*/
int main() {
    struct tm *tm;
    time_t timep;

    time(&timep);
    tm = localtime(&timep);

    printf("time(sec): %d\n", (int)timep);
    printf("time(date): %s\n", asctime(tm));
}