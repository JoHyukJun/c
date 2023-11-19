/*
    - 다음은 정숫값 2개를 변수 a와 b로 읽어 들인 후 a를 b로 나눈 몫과 나머지를 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int a, b;

    puts("input 2 number.");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    printf("%d / %d = %d and %d", a, b, a / b, a % b);
    
    return 0;
}