/*
    - 다음은 123123... 을 no 문자만큼 출력하는 프로그램 일부다.
    - 예를 들어 no 가 8 이면 12312312 라고 출력하고 4면 1231 이라고 출력한다.
*/


#include <stdio.h>


void refeat_num(int no) {
    int i;

    for (i = 0; i < no; i++)
        putchar(i % 3 + 1 + '0');

    putchar('\n');
}

int main(void) {
    refeat_num(8);
    refeat_num(4);

    return 0;
}