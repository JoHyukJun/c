/*
    - 다음은 n1, n2 중 어느 쪽이 큰지 출력하면서 두 값의 차이도 함께 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n1, n2;

    puts("input 2 number.");
    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);

    if (n1 > n2) {
        printf("n1 > n2\n");
        printf("diff: %d\n", n1 - n2);
    }
    else {
        printf("n1 < n2\n");
        printf("diff: %d\n", n2 - n1);
    }

    return 0;
}