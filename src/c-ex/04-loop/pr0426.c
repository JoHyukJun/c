/*
    - 다음은 기호 문자 '+' 를 w 개 마다 줄 바꿈 하면서 모두 n 개 출력하는 프로그램이다.
    - n 과 w 는 양의 정숫값이다.
    - 마지막 '+' 를 출력한 다음 출력할 줄 바꿈 문자는 1개뿐이어야 하며 2개 이상 출력해서는 안된다.
*/


#include <stdio.h>


int main(void) {
    int w, n;
    int i;

    for (i = 1; i <= n; i++) {
        putchar('+');

        if (i % w == 0)
            putchar('\n');
    }

    if (i % w == 0)
        putchar('\n');

    return 0;
}