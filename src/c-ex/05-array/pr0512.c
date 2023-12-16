/*
    - 다음은 요소 수가 n 인 배열 a 안의 값이 양수인 요소 개수를 구하는 프로그램 일부다.
*/


#include <stdio.h>


int main(void) {
    int i, j, n;

    puts("input arr size.");
    scanf("%d", &n);

    int a[n];

    int count = 0;

    for (i = 0; i < n; i++)
        if (a[i] > 0)
            count++;
    
    return 0;
}