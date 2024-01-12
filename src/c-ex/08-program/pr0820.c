/*
    - 다음 함수를 rec(3) 이라고 하출했을 떄의 실행 결과를 나타내라.
    ->
        1 2 3 1
*/


#include <stdio.h>


void rec(int no) {
    if (no > 0) {
        rec(no - 1);
        printf("%d ", no);
        rec(no - 2);
    }
}

int main(void) {
    rec(3);

    return 0;
}