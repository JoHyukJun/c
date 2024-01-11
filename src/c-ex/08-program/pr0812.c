/*
    - 다음은 앞의 swap 함수를 이용해 float 형 배열 v 의 요소를 오름차순으로 다시 정렬하는 함수다.
*/


#include <stdio.h>

#define NUMBER 5

#define swap(type, x, y) do {type t = x; x = y; y = t; } while(0)


void bsort(float v[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (v[j - 1] > v[j])
                swap(float, v[j - 1], v[j]);
        }
    }
}

int main(void) {
    int i;
    float varr[NUMBER] = {4.1, 3.2, 3.3, 1.4, 4.5};

    for (i = 0; i < NUMBER; i++)
        printf("varr[%d]:%lf\n", i, varr[i]);

    printf("########################\n");

    bsort(varr, NUMBER);

    for (i = 0; i < NUMBER; i++)
        printf("varr[%d]:%lf\n", i, varr[i]);

    return 0;
}