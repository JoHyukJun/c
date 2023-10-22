/*
    - printf("ABCDE\n");
        - 형식 설정이나 숫자 출력 등도 가능
        - 줄 바꿈 문자 출력은 명시적으로 지정해야 함
    - puts("ABCDE");
        - 형식 설정이나 숫자 출력 등은 불가능
        - 줄 바꿈 문자가 자동으로 출력됨
*/


#include <stdio.h>


int main(void) {
    int n1, n2, n3;
    int add;

    puts("input 3 num");
    printf("n1: ");
    scanf("%d", &n1);
    printf("n2: ");
    scanf("%d", &n2);
    printf("n3: ");
    scanf("%d", &n3);

    add = n1 + n2 + n3;

    printf("sum: %d\n", add);

    return 0;
}