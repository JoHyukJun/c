/*
    - 다음은 int 형 변수 x, y 로 읽어 들인 값이 둘 다 홀수인지, 한쪽이 짝수고 다른쪽이 홀수인지, 둘 다 짝수인지 판정해서 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int x, y;
    int cnt = 0;

    puts("input 2 number.");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    if (x % 2 == 0) cnt = cnt + 1;
    if (y % 2 == 0) cnt = cnt + 1;

    switch (cnt))
    {
    case 0:
        puts("둘 모두 홀수입니다.");
        break;
    case 1:
        puts("짝수와 홀수입니다.");
        break;
    case 2:
        puts("둘 모두 짝수입니다.");
        break;
    }

    return 0;
}