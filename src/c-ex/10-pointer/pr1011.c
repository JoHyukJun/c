/*
    - 다음 함수 swap 은 px 와 py 가 가리키는 int 형 변수의 값을 교환하는 함수다.
    - 함수 sort2 는 n1 과 n2 가 가리키는 int 형 변수를 오름차순으로 정렬하는(n1 이 가리키는 변수쪽이 더 작도록 하는) 함수다.
    - 함수 sort3 는 n1, n2, n3 이 가리키는 int 형 변수를 오름차순으로 정렬하는 함수다.
*/


#include <stdio.h>


void swap(int *px, int *py) {
    int temp = *px;

    *px = *py;
    *py = temp;
}

void sort2(int *n1, int *n2) {
    if (*n1 > *n2) swap(n1, n2);
}

void sort3(int *n1, int *n2, int *n3) {
    if (*n1 > *n2) swap(n1, n2);
    if (*n2 > *n3) swap(n2, n3);
    if (*n1 > *n3) swap(n1, n3);
}

int main(void) {
    int na, nb, nc;

    puts("3개의 정수를 입력해주세요.");
    printf("정수 A: "); scanf("%d", &na);
    printf("정수 B: "); scanf("%d", &nb);
    printf("정수 C: "); scanf("%d", &nc);

    sort3(&na, &nb, &nc);

    puts("sort3");
    printf("정수 A는 %d 입니다.\n", na);
    printf("정수 B는 %d 입니다.\n", nb);
    printf("정수 C는 %d 입니다.\n", nc);

    return 0;
}