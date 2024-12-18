#include "timelib.h"


int print_timelib()
{
    printf("TIMELIB\n");

    return 0;
}

int print_current_time()
{
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);

    printf("%d-%d-%d %d:%d:%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}

int get_current_time_str_t1(char *buf)
{
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);

    sprintf(buf, "%d-%d-%d %d:%d:%d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}

int get_current_time_str_t2(char *buf)
{
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);

    sprintf(buf, "%d-%02d-%02d %02d:%02d:%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}

int get_current_time_str_t3(char *buf)
{
    time_t t;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);

    sprintf(buf, "%04d%02d%02d%02d%02d%02d", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);

    return 0;
}
