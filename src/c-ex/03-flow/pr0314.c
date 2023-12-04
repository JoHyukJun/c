/*
    - 다음은 no값이 13의 제곱근 이하면 그 내용을 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int no;

    puts("input 1 number.");
    printf("no: ");
    scanf("%d", &no);

    if (no * no <= 13)
        puts("under 13")

    return 0;
}