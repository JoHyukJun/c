/*
    - 다음은 모두 + 를 no 개 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int no, i;

    puts("input 1 number.");
    scanf("%d", &no);

    i = 0;

    while (i < no) {
        i++;
        putchar('+');
    }

    putchar('\n');

    i = 1;

    while (i <= no) {
        i++;
        putchar('+');
    }

    putchar('\n');

    i = no;

    while (i-- > 0)
        putchar('+');

    putchar('\n');

    i = no;

    while (--i >= 0)
        putchar('+');

    putchar('\n');

    for (i = 0; i < no; ++i)
        putchar('+');

    putchar('\n');

    for (i = 1; i <= no; i++)
        putchar('+');

    putchar('\n');

    return 0;
}