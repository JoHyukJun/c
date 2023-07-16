#include <time.h>
#include <stdio.h>


int main() {
    struct tm *tm;
    time_t timep;

    time(&timep);
    printf("time(sec): %d\n", (int)timep);

    tm = gmtime(&timep);
    printf("gmtime=Y: %d ", tm->tm_year);
    printf("M: %d ", tm->tm_mon);
    printf("D: %d ", tm->tm_mday);
    printf("H: %d ", tm->tm_hour);
    printf("M: %d ", tm->tm_min);
    printf("S: %d ", tm->tm_sec);

    tm = localtime(&timep);
    printf("gmtime=Y: %d ", tm->tm_year);
    printf("M: %d ", tm->tm_mon);
    printf("D: %d ", tm->tm_mday);
    printf("H: %d ", tm->tm_hour);
    printf("M: %d ", tm->tm_min);
    printf("S: %d ", tm->tm_sec);
}