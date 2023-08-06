#include <sys/types.h>
#include <time.h>
#include <stdio.h>


/*
    - 리눅스 시스템은 1970년 1월 1일 0시 0분 0초(그리니치 표준시)부터 현재까지 경과한 시간을 초 단위로 저장하고 이를 기준으로 시간 정보 관리
    - time_t time(time_t *tloc);
        - time() 함수는 utc부터 현재까지 경과된 시간을 초 단위로 표시
        - tloc 가 null 이 아니면 tloc 이 가리키는 주소에 시간 정보 저장
        - null 이면 시간 정보 return
*/
int main() {
    time_t tloc;

    time(&tloc);
    printf("time(sec): %d\n", (int)tloc);
}