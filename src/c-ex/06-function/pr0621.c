/*
    - 다음은 요소 개수가 n 인 배열 a 에서 btm 이상 top 이하의 값을 가진 요소 중 가장 앞쪽에 있는 요소의 첨자를 반환하는 (해당 요소가 없다면 -1을 반환) 함수다.
*/


#include <stdio.h>

#define NUMBER 5


int search_range(const int a[], int btm, int top, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (a[i] >= btm && a[i] <= top)
            return i;
    }

    return -1;
}

int main(void) {
    int a[NUMBER] = {1, 2, 3, 4, 5};

    printf("search_range(a, 3, 4, NUMBER): %d\n", search_range(a, 3, 4, NUMBER));
    printf("search_range(a, 1, 4, NUMBER): %d\n", search_range(a, 1, 4, NUMBER));
    printf("search_range(a, 7, 8, NUMBER): %d\n", search_range(a, 7, 8, NUMBER));

    return 0;
}