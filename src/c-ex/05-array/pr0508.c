/*
    - 다음은 요소 개수가 5인 int 형 배열 a 의 요소에 앞에서부터 순서대로 10, 20, 30, 40, 50 을 대입하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int a[5];
    int i;

    for (i = 0; i < 5; i++)
        a[i] = (i + 1) * 10;

    return 0;
}