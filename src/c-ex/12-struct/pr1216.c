/*
    - 다음은 ABC 형 구조체 배열 a 의 모든 멤버가 k 와 똑같은 모든 요소의 첨자를 배열 idx 에 저장하는 프로그램 일부다.
    - 함수 ABCsearch 는 k 와 같은 배열 a 요소의 첨자가 1, 4, 5 면 배열 idx 에 대해 앞에서부터 순서대로 1, 4, 5 를 저장하고 그 개수인 3 을 반환한다.
*/


#include <stdio.h>

#define NUMBER 5


typedef struct {
    short   a;
    int     b;
    long    c;
} ABC;


int ABCeq(const ABC *x, const ABC *y) {
    if (x->a != y->a) return 0;
    if (x->b != y->b) return 0;
    if (x->c != y->c) return 0;

    return 1;
}

int ABCsearch(const ABC a[], ABC k, int n, int idx[]) {
    int i;
    int count = 0;

    for (i = 0; i < n; i++) {
        if (ABCeq(&a[i], &k)) {
            idx[count++] = i;
        }
    }

    return count++;
}


int main(void) {
    ABC a[NUMBER] = {
        {1, 2, 3},
        {2, 3, 3},
        {1, 3, 4},
        {1, 2, 3},
        {1, 2, 3},
    };

    ABC k = {1, 2, 3};

    int i;
    int idx[128] = {0};

    for (i = 0; i < NUMBER; i++) {
        printf("a.a = %hd\n", a[i].a);
        printf("a.b = %d\n", a[i].b);
        printf("a.c = %ld\n", a[i].c);
    }

    printf("ABCsearch(a, k, NUMBER, idx) = %d\n", ABCsearch(a, k, NUMBER, idx));

    for (i = 0; i < 128; i++) {
        printf("idx[%d] = %d\n", i, idx[i]);
    }

    return 0;
}