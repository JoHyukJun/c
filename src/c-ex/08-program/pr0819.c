/*
    - 다음은 음이 아닌 정수 n 의 계승값을 구해 반환하는 함수다.
    - 이처럼 함수 안에서 자기 자신과 똑같은 함수를 호출하는 것을 (1) 함수 호출이라고 한다.
    - (1): 재귀
*/


#include <stdio.h>


int fact(int n) {
    if (n > 0)
        return (n * fact(n - 1));
    else
        return 1;
}

int main(void) {
    printf("fact(4):%d\n", fact(4));
    printf("fact(5):%d\n", fact(5));
    printf("fact(6):%d\n", fact(6));
    printf("fact(10):%d\n", fact(10));

    return 0;
}