/*
    - 다음은 1 이상 100 이하의 정수를 변수 n 으로 읽어 들이는 (범위 밖의 값을 입력하면 다시 입력하도록 함) 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int n;

    do {
        printf("input 1 ~ 100 number.");
        scanf("%d", &n);

        if (n < 0 || n > 100)
            puts("wrong number.");
    } while(n < 0 || n > 100);

    while (1)
    {
        printf("input 1 ~ 100 number.");
        scanf("%d", &n);

        if (n >= 0 && n <= 100)
            break;
            
        puts("wrong number.");
    }
    

    return 0;
}