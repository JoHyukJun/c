/*
    - 다음은 1 부터 n 까지의 합을 구해서 반환하는 함수다.
    - n 은 양의 정수
*/


#include <stdio.h>


int sumpup(int n) {
    int i;
    int sum = 0;

    for (i = 1; i <= n; i++)
        sum += i;

    return sum;
}

int main(void) {
    printf("sumpup(3): %d\n", sumpup(3));
    printf("sumpup(4): %d\n", sumpup(4));
    printf("sumpup(8): %d\n", sumpup(8));

    return 0;
}