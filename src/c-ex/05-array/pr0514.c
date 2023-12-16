/*
    - 다음은 요소 개수가 n 인 int 형 배열 a 의 요소 중 최댓값과 최솟값의 차이를 구해 출력하는 프로그램 일부다.
*/


#include <stdio.h>

#define n 5


int main(void) {
    int i, min, max;
    int a[n];

    min = max = 0;

    for (i = 0; i < n; i++)
        a[i] = i + 1;

    for (i = 0; i < n; i++) {
        if (a[i] < min) min = a[i];
        if (a[i] > max) max = a[i];
    }

    printf("diff max min: %d\n", max - min);

    return 0;
}