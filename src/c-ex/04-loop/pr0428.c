/*
    - 다음은 기호 문자 '+' 를 w 개마다 줄 바꿈 하면서 모두 n 개 출력하는 프로그램이다.
    - 출력할 떄는 3행마다 빈 행을 출력한다.
    - 마지막 '+' 를 출력한 다음에는 줄 바꿈 문자를 1개만 출력하며 2개 이상 출력해서는 안 된다.
    - n 과 w 는 양의 정수다.
*/


#include <stdio.h>


int main(void) {
    int n, w;
    int i, j;

    puts("input 2 number.");
    scanf("%d", &n);
    scanf("%d", &w);

    int p = n / w;
    int q = n % w;

    for (i = 1; i <= p; i++) {
        for (j = 1; j <= w; j++)
            putchar('+');

        putchar('\n');

        if (i % 3 == 0 && i < p)
            putchar('\n');
    }

    for (i = 1; i <= q; i++)
        putchar('+');

    if (q != 0) putchar('\n');

    return 0;
}