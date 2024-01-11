/*
    - 다음과 같이 매크로를 정의했다.
    - MAX 는 (1) 매크로, max2 는 (2) 매크로다.
    - (1): 객체 형식
    - (2): 함수 형식
*/


#include <stdio.h>

#define MAX 125

#define mas2(x, y) (((x) > (y)) ? x : y)


int main(void) {
    return 0;
}