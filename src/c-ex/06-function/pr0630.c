/*
    - 다음 함수가 무엇을 수행하는지 설명하라.
    -> 정적 기억 수명 변수인 v 를 입력받은 파리미터 v 로 재할당하고 기존 v 변수의 값을 return 하는 함수.
*/


#include <stdio.h>


int val(int no) {
    static int v;
    int temp = v;

    v = no;

    return temp;
}

int main(void) {
    return 0;
}