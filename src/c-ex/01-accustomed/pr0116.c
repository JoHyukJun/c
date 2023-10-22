/*
    - 다음은 정숫값을 읽어 들여 이를 5배 한 값을 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int n1;

    printf("input number: ");
    scanf("%d", &n1);

    printf("input number * 5 = %d\n", n1 * 5);

    return 0;
}