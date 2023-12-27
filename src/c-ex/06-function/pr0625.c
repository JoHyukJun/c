/*
    - 다음 프로그램 일부의 실행 결과를 나타내라
    - 함수 fn 의 반환형이나 인수에 관한 사용을 분명하기 위한 (1) 선언이다.
    - (1): 함수 원형
    ->
        1 1 1
        1 2 2
        1 3 3
*/


#include <stdio.h>


int main(void) {
    void fn(int i);
    int i;

    for (i = 0; i < 3; i++)
        fn(i);

    return 0;
}

void fn(int c) {
    int a = 0;

    static int b = 0;

    printf("%d %d %d\n", ++a, ++b, ++c);
}