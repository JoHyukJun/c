/*
    - 다음은 1 부터 n 가지 모든 정수의 곱을 구해 fact 에 대입함과 동시에 그 계산식과 결과를 출력하는 프로그램의 일부다. (예를 들어 n 이 5면 fact 에 120을 대입함과 동시에 "1 * 2 * 3 * 4 * 5 = 120" 을 출력)
    - n 에는 1이상의 양의 정숫값을 입력한다.
*/


#include <stdio.h>


int main(void) {
    int n, fact, i;

    puts("input 1 number.");
    scanf("%d", &n);

    fact = 1;

    for (i = 1; i < n; i++) {
        printf("%d * ", i);
        fact *= i;
    }

    fact *= n;

    printf("%d = %d\n", n, fact);

    return 0;
}