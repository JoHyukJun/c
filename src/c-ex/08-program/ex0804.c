#include <stdio.h>

#define alert2() (printf("\a\a"))
#define puts_alert2(str) (alert2(), puts(str))


int main(void) {
    int n;

    puts("1개의 정수를 입력하시오.");
    printf("n: "); scanf("%d", &n);

    if (n)
        puts_alert2("이 수는 0이 아닙니다.");
    else
        puts_alert2("이 수는 0입니다.");

    return 0;
}