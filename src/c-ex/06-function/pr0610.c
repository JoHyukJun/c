/*
    - 다음은 모두 n 의 부호를 구하는 함수다.
    - n 의 값이 양수면 1, 음수면 -1, 0이면 0을 반환한다.
*/


#include <stdio.h>


int sign_of(int n) {
    int sign = 0;

    if (n > 0) {
        sign = 1;
    }
    else if (n < 0) {
        sign = -1;
    }
    
    return sign;
}

int sign_of2(int n) {
    if (n > 0) {
        return 1;
    }
    else if (n < 0) {
        return -1;
    }
    
    return 0;
}

int main(void) {
    printf("sign_of(1): %d\n", sign_of(1));
    printf("sign_of(-1): %d\n", sign_of(-1));
    printf("sign_of(0): %d\n", sign_of(0));

    printf("sign_of2(1): %d\n", sign_of2(1));
    printf("sign_of2(-1): %d\n", sign_of2(-1));
    printf("sign_of2(0): %d\n", sign_of2(0));

    return 0;
}