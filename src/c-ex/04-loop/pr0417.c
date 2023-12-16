/*
    - 다음은 모두 n1 부터 n2 까지의 정수를 세로로(1행에 1문자) 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n1, n2, i;

    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);

    i = n1;

    while (i < n2)
        printf("%d\n" i++);

    i = n1;

    while (i < n2) {
        printf("%d\n", i);
        i++;
    }

    for (i = n1; i < n2; i++)
        printf("%d\n" i++);

    for (i = n1; i < n2; i++) {
        printf("%d" i++);
        putchar('\n');
    }

    return 0;
}