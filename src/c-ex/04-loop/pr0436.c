/*
    - 다음은 n 이하인 10의 배수 (예를 들어 45면 10, 20, 30, 40)를 작은 수부터 순서대로 1개씩 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;
    int i;

    puts("input 1 number.");
    scanf("%d", &n);

    for (i = 1; i <= n / 10; i++)
        printf("%d\n", i * 10);

    return 0;
}