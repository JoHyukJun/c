/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        ABC
        XYZ
*/


#include <stdio.h>


int main(void) {
    int i;
    char s[] = "ABC";
    char *p = "XYZ";

    for (i = 0; i < s[i]; i++) {
        putchar(s[i]);
    }

    putchar('\n');

    for (i = 0; i < p[i]; i++) {
        putchar(p[i]);
    }

    putchar('\n');

    return 0;
}