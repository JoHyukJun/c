#include <grp.h>
#include <stdio.h>


/*
    - struct group *getgrnam(const char *name);
    - gr_name
        - 그룹명을 저장
    - gr_passwd
        - 그룹 패스워드를 저장
        - 보통은 공백
        - 그룹 패스워드를 지정하면 사용자 패스워드처럼 암호화되어 문자 저장
        - 그룹 패스워드를 설정하는 명령은 없으므로 사용자 패스워드 파일에서 복사해 삽입
        - 그룹 패스워드가 지정되어 있으면 사용자는 newgrp 명령을 사용해 다른 그룹으로 변경할 때 이 패스워드 입력
    - gr_gid
        - 그룹 id 번호 저장
    - gr_mem
        - 그룹의 멤버인 로그인명 저장
*/
int main() {
    struct group *grp;
    int n;

    grp = getgrnam("jo");
    printf("group name: %s\n", grp->gr_name);
    printf("gid: %d\n", (int)grp->gr_gid);

    n = 0;
    printf("members: ");
    while (grp->gr_mem[n] != NULL) {
        printf("%s ", grp->gr_mem[n++]);
    }

    printf("\n");
}