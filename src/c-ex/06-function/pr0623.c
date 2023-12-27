/*
    - 다음은 요소 개수 n 인 배열 a 에서 양의 값을 가진 요소 중 가장 끝에 있는 요소의 첨자를 반환(해당 요소가 없을 때는 -1을 반환) 하는 함수다.
*/


#include <stdio.h>

#define NUMBER 5


int search_plusr_r(const int a[], int n) {
    while (--n) {
        if (a[n] > 0)
            return n;
    }

    return -1;
}

int main(void) {
    int a[NUMBER] = {3, 4, 5, -1, -2};

    printf("search_plusr_r(a, NUMBER): %d\n", search_plusr_r(a, NUMBER));

    return 0;
}