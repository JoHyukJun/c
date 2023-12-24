/*
    - 다음은 요소 개수가 n 개인 배열 a 안의 값이 양수인 요소를 배열 b 에 순서대로 복사하는 프로그램이다. 변수 count 는 복사한 요소의 개수다.
*/


#include <stdio.h>


int main(void) {
    int n = 4;
    int a[n];
    int b[n];
    int count = 0;

    for (i = 0; i < n; i++)
        if (a[i] > 0)
            b[count++] = a[i];

    return 0;
}