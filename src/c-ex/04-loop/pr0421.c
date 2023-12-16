/*
    - 다음은 양의 정수 n 의 모든 자리 합계를 변수 sum 에 저장하는 프로그램이다. (에를 들어 n 이 513 이라면 sum 의 값은 5 + 1 + 3 = 9 가 된다.)
*/


#include <stdio.h>


int main(void) {
    int n, sum;

    puts("input 1 number.");
    scanf("%d", &n);

    sum = 0;

    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }

    printf("sum: %d\n", sum);

    return 0;
}