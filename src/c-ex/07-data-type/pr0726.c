/*
    - 다음은 전달받은 unsigned 형의 제 15비트부터 제 0비트까지 16비트를 0과 1의 나열로 출력하는 함수다.
    - 마지막에 줄 바꿈 출력
*/


#include <stdio.h>


void print16bits(unsigned x) {
    int i;

    for (i = 15; i >=0; i--)
        putchar(((x >> i) & 1U) ? '1': '0');
    putchar('\n');
}

int main(void) {
    unsigned  x;

    printf("x: "); scanf("%u", &x);

    printf("\nx                 : "); print16bits(x);
    putchar('\n');

    return 0;
}