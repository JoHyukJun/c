#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


/*
    - uid_t getuid(void);
        - RUID(Real User ID)
            - 로그인할 떄 사용한 로그인명에 대응하는 UID
            - 프로그램을 실행하는 사용자
    - uid_t geteuid(void);
        - EUID(Effective User ID)
            - 프로세스에 대한 접근 권한을 부여할 떄 사용
            - 처음 로그인할 때는 RUID와 EUID가 같지만 setuid가 설정된 프로그램을 실행하거나 다른 사용자 ID로 변경할 경우 EUID 변경
    - char *getlogin(void);
        - /var/run/utmp 파일을 검색해 현재 프로세스를 실행한 사용자의 로그인명을 찾아 리턴
*/
int main() {
    uid_t uid, euid;
    char *name;

    uid = getuid();
    euid = geteuid();
    name = getlogin();

    printf("login name = %s, uid = %d, euid = %d\n", name, (int)uid, (int)euid);
}