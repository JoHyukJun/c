/*
    - 다음과 같이 (1) 체 선언이 주어졌다고 하자.
    - 이떄 aaa 는 (2) 라고 하며 'enum aaa' 가 자료형이 된다. 또한 a1, a2, a3 은 (3) 라고 하며 각각의 값은 (4), (5), (6) 이다.
    - (1): 열거
    - (2): 열거체 태그
    - (3): 열거 상수
    - (4): 0
    - (5): 5
    - (6): 6
*/


#include <stdio.h>


enum aaa {a1, a2 = 5, a3};

int main(void) {
    return 0;
}