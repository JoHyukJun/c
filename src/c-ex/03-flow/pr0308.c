/*
    - 다음은 n값의 자릿수(0인지, 1자리인지, 2자리인지)를 판정해서 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;

    puts("input 1 number.");
    printf("n: ");
    scanf("%d", &n);
    
    if (n == 0)
        puts("0");
    else if (n >= -9 || n <= 9)
        puts("1");
    else
        puts("2");

    return 0;
}