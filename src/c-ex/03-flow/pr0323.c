/*
    - 다음은 no값이 양수면 최하위 자리가 7인지 판정해서 출력하고, 그렇지 않으면 "no는 양수가 아닙니다." 라고 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int no;

    puts("input 1 number.");
    printf("no: ");
    scanf("%d", &no);

    if (no > 0)
        if (no % 10 == 7)
            puts("no의 최하위 자리는 7입니다.");
        else
            puts("no의 최하위 자리는 7이 아닙니다.");
    else
        puts("no는 양수가 아닙니다.");

    if (no > 0)
    {
        printf("no의 최하위 자리는 7");

        if (no % 10 == 7)
            puts("입니다.");
        else
            puts("이 아닙니다.");
    }
    else
        puts("no는 양수가 아닙니다.");

    return 0;
}