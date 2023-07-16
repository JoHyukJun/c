#include <time.h>
#include <stdio.h>


/*
    - 리눅스는 기본 시간대 정보를 환경 변수 TZ에 설정
    - 시스템의 기본 시간대 정보는 /etc/default/init 파일에 "TZ=ROK"와 같은 형태로 저장
    - void tzset(void);
        - 현재 지역의 시간대로 설장
    - extern char *tzname[2];
        - 지역 시간대와 보정된 시간대명을 약어로 저장
    - extern long timezone;
        - UTC와 지역 시간대와의 시차를 초 단위로 저장
    - extern int daylight:
        - 서머타임제를 시행하면 0이 아니고, 그렇지 않으면 0
*/
int main() {
    tzset();

    printf("timezone: %d\n", (int)timezone);
    printf("daylight: %d\n", daylight);
    printf("tzname[0]: %s\n", tzname[0]);
    printf("tzname[1]: %s\n", tzname[1]);
}