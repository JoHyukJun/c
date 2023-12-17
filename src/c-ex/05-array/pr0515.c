/*
    - 다음은 요소 개수가 n 인 배열 a 의 모든 요소를 더하는 식과 합계 값을 출력하는 프로그램 일부다.
    - 예를 들어 요소 개수가 5이고 요소 값이 앞쪽부터 순서대로 11, 32, 18, 24, 66 이면 '11 + 32 + 18 + 24 + 66 = 151' 이라고 출력한다.
*/


#include <stdio.h>

#define n 5


int main(void) {
    int i;
    int sum;
    int a[n];

    for (i = 0; i < n; i++)
        a[i] = i + 1;

    sum = 0;

    for (i = 0; i < n - 1; i++) {
        sum += a[i];
        printf("%d + ", a[i]);
    }

    sum += a[n - 1];

    printf("%d = %d\n", a[i], sum);

    sum = 0;

    for (i = 0; i < n; i++) {
        sum += a[i];

        if (i != n - 1)
            printf("%d + ", a[i]);
        else
            printf("%d = ", a[i]);
    }

    printf("%d\n", sum);

    return 0;
}