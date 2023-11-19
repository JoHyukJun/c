/*
    - 다음은 읽어 들인 정숫값의 가장 자리에 있는 수를 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int n;

    printf("integer: ");
    scanf("%d", &n);

    printf("low number: %d\n", n % 10);

    return 0;
}