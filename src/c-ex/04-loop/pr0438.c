/*
    - 다음은 변수 n이 양수면 n 부터 0 까지 카운트다운을 출력하고 음수면 0까지 카운트업을 울력하며 0이면 아무것도 수행하지 않는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int no;
    int i;

    puts("input 1 number.");
    scanf("%d", &no);

    if (no > 0) {
        for (i = no; i >= 0; i--) {
            printf("%d ", i);
        }
        putchar('\n');
    }
    else if (no < 0) {
        for (i = no; i <= 0; i++) {
            printf("%d ", i);
        }
        putchar('\n');
    }

    return 0;
}