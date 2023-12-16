/*
    - 다음은 height 행 width 열인 평행사변형 (윗변과 밑변이 수평이고 단이 내려갈 떄마다 1문자씩 당겨 쓴것) 을 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int height, width;
    int i, j;

    height = 3;
    width = 5;

    for (i = 0; i < height; i++) {
        for (j = 0; j < height - i; j++)
            putchar(' ');

        for (j = 0; j < width; j++)
            putchar('*');
        putchar('\n');
    }
    
    return 0;
}