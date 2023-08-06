#include <sys/types.h>
#include <utmp.h>
#include <stdio.h>


/*
    - who 명령어로 현재 시스템에 로그인한 사용자 정보 검색 가능
    - last 명령어로 시스템의 부팅 시각 정보나 사용자 로그인 검색 기록 검색 가능
    - ubuntu linux 에서는 로그인 정보를 /var/run/utmp 와 /var/log/wtmp 파일에 저장
    - struct utmp
        - ut_type
            - 현재 읽어온 항목에 저장된 데이터 형식
            - EMPTY
                - 빈 항목
            - RUN_LVL
                - 시스템의 런레벨 변경되었음을 표시
            - BOOT_TIME
                - 시스템 부팅 시각
            - NEW_TIME
                - 시스템 클럭 변경된 다음 시간 정보
            - OLD_TIME
                - 시스템 클럭 변경되기 전의 시간 정보
            - INIT_PROCESS
                - init이 생성한 프로세스임을 표시
            - LOGIN_PROCESS
                - 사용자 로그인을 위한 세션 리더 프로세스
            - USER_PROCESS
                - 일반 프로세스
            - DEAD_PROCESS
                - 종료한 프로세스
            - ACCOUNTING
                - 사용하지 않는 항모
        - ut_line
            - 사용자가 로그인한 장치명
        - ut_id
            - 터미널 이름이거나 /etc/inittab 파일에서 읽어온 id
        - ut_user
            - 사용자명 저장
        - ut_exit
            - 프로세스가 DEAD_PROCESS인 경우 프로세스의 종료 상태 저장
        - ut_session
            - 해당 정보의 세션 번호
        - ut_tv
            - 해당 정보를 마지막으로 변경한 시각
        - ut_addr_v6
            - 원격 접속한 경우 원격 호스트의 인터넷 주소 저장
        - _unused
            - 추후 사용을 위해 예약
*/
int main() {
    struct utmp *ut;

    printf("login name line\n");
    printf("---------------\n");

    while ((ut = getutent()) != NULL) {
        if (ut->ut_type != USER_PROCESS) {
            continue;
        }

        printf("%s         %s\n", ut->ut_user, ut->ut_line);
    }
}