/*
    - 다음은 모두 +-+- 를 no 개 문자 표시하는 프로그램의 일부다.
    - 예를 들어 no 가 4면 +-+-라고 출력하고 7이면 +-+-+-+ 라고 출력한다.
*/


#include <stdio.h>


int main(void) {
    int no, i;

    puts("input 1 number.");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        putchar(i % 2 == 0 ? '+' : '-');

    putchar('\n');

    for (i = 1; i <= no; i++)
        putchar(i % 2 == 1 ? '+' : '-');

    putchar('\n');

    for (i = 0; i < (no / 2); i++)
        printf("+-");
    
    if (no % 2 == 1)
        putchar('+');

    putchar('\n');

    for (i = 1; i <= (no / 2); i++)
        printf("+-");

    if (no % 2 == 1)
        putchar('+');

    putchar('\n');

    return 0;
}