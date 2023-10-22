/*
    - 다음은 3개의 정숫값을 읽어 들이 다음 이들 값의 곱을 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int n1, n2, n3;

    puts("input 3 number");
    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);
    printf("n3: ");
    scanf("%d", &n3);

    printf("n1 * n2 * n3 = %d\n", n1 * n2 * n3);


    return 0;
}