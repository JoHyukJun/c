/*
    - 다음은 요소 개수가 n 인 배열 a 안의 값이 양수인 요소를 배열 b 에 순서대로 복사한 다음, 복사한 요소의 개수를 반환하는 함수다.
*/


#include <stdio.h>


int plus_of(const int a[], int b[], int n) {
    int i, count = 0;
    
    for (i = 0; i < n; i++) {
        if (a[i] > 0)
            b[count++] = a[i];
    }

    return count;
}

int main(void) {
    int n = 5;

    int a[] = {3, -1, -2, 4, 5};
    int b[n];

    printf("plus_of(a, b, n): %d\n", plus_of(a, b, n));

    return 0;
}