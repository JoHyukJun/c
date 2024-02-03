/*
    - 다음은 앞 문제의 ABC 형 구조체 배열 a 요소의 모든 멤버 값을 출력하는 함수다.
    - 값을 출력하는데 필요한 최소한의 자릿수로 출력
*/


#include <stdio.h>

#define NUMBER 5


typedef struct {
    short   a;
    int     b;
    long    c;
} ABC;


void ABCprint_array(const ABC *a, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("a[%d].a = %hd\n", i, a[i].a);
        printf("a[%d].b = %d\n", i, a[i].b);
        printf("a[%d].c = %ld\n", i, a[i].c);
    }
}

int main(void) {
    ABC a[NUMBER] = {
        {1, 2, 3},
        {2, 3, 3},
        {1, 3, 4},
        {1, 2, 3},
        {1, 2, 3},
    };

    ABCprint_array(a, NUMBER);

    return 0;
}