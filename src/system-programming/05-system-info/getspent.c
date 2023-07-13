#include <shadow.h>
#include <stdio.h>


/*
    - struct spwd *getspent(void);
        - /etc/shadow 파일에서 패스워드 정보를 순차적으로 읽기
    - void setspent(void);
        - /etc/shadow 파일의 오프셋을 파일의 처음으로 위치
    - void endspent(void);
        - /etc/shadow 파일 닫기
    - struct spwd *fgetspent(FILE *stream);
        - /etc/shadow 파일이 아닌 파일 포인터로 지정한 다른 파일에서 패스워드 정보를 읽기
*/
int main() {
    struct spwd *spw;
    int n;

    for (n = 0; n < 3; n++) {
        spw = getspent();
        printf("login name: %s, passwd: %s\n", spw->sp_namp, spw->pwdp);
    }
}