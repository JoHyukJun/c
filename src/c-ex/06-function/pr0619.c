/*
    - 다음은 호출된 횟수를 반환하는 함수다.
    - 예를 들어 처음에 호출됐을 때는 1을, 두 번째 호출됐을 때는 2를 반환한다.
*/


#include <stdio.h>


int counter(void) {
    static int c = 0;

    return ++c;
}

int main(void) {
    printf("counter(): %d\n", counter());
    printf("counter(): %d\n", counter());
    printf("counter(): %d\n", counter());
    printf("counter(): %d\n", counter());
    
    return 0;
}