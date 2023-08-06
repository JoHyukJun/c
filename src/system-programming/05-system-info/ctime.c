#include <time.h>
#include <stdio.h>


/*
    - char *ctime(const time_t *timep);
        - ctime() 함수는 초  단위 시간을 인자로 받아 문자열로 리턴
*/
int main() {
    time_t timep;

    time(&timep);

    printf("time(sec): %d\n", (int)timep);
    printf("time(date): %s\n", ctime(&timep));
}