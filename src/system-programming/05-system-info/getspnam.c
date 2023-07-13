#include <shadow.h>
#include <stdio.h>


/*
    - stcurt spwd *getspnam(const char *name);
        - 인자로 지정한 사용자의 패스워즈 정보를 읽기
    - sp_namp
        - 로그인명을 저장
    - sp_pwdp
        - 사용자 계정의 패스워드를 암호화해 저장
    - sp_lstchg
        - 패스워드를 변경한 날짜 정보로 1970년 1월 1일부터 일 수로 계산해 저장
    - sp_min
        - 변경된 패스워드를 사용해야 하는 최소 일 수
    - sp_max
        - 현재 패스워드를 사용할 수 있는 최대 일 수
    - sp_warn
        - 패스워드를 변경할 날이 도기ㅣ 전에 경고를 시작하는 일 수
    - sp_inact
        - 패스워드가 만료된 이후 사용자 계정이 정지될 때까지의 일 수
    - sp_expire
        - 사용자 계정이 만료되는 날짜 정보
    - sp_flag
        - 나중에 사용하기 위해 예약된 공간
*/
int main() {
    struct spwd *spw;

    spw = getspnam("jo");
    printf("login name: %s\n", spw->sp_namp);
    printf("passwd: %s\n", spw->sp_pwdp);
    printf("last change: %ld\n", spw->sp_lstchg);
}