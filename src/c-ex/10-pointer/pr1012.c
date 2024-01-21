/*
    - 다음은 2 개의 정숫값 x 와 y 의 최대 공약수를 구해 반환하는 함수 gcd 와, 이 함수 gcd 를 이용해 요소 개수 n 인 int 형 배열 a 의 모든 요소의 최대 공약수를 구해 반환하는 함수 gcdary 다.
*/


#include <stdio.h>


int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int gcdary(const int a[], int n) {
    if (n == 1)
        return a[0];
    else if (n == 2)
        return gcd(a[0], a[1]);
    else
        return gcd(a[0], gcdary(&a[1], n - 1));
}

int main(void) {
    int v[] = {4, 8, 12, 16, 20};

    printf("gcdary: %d\n", gcdary(v, 5));

    return 0;
}