/*
    - 다음은 모두 줄 바꿈 문자를 n 번 출력하는 함수다.
*/


#include <stdio.h>


void put_newline(int n) {
    while (n-- > 0) {
        putchar('\n');
    }
}

void put_newline2(int n) {
    int i;

    for (i = 1; i <= n; i++) {
        putchar('\n');
    }
}

int main(void) {
    put_newline(3);
    put_newline2(4);
    
    return 0;
}