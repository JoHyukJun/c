/*
    - 다음은 height 행 width 열의 숫자를 출력하는 프로그램의 일부다.
    - 1행째에는 1234567890...을 열의 개수만큼 출력하고, 2행째에는 2345678901... 을 열의 개수만큼 출력한다.
    - 이하도 마찬가지다.
*/


#include <stdio.h>


int main(void) {
    int height, width;
    int i, j;

    height = 11;
    width = 12;

    for (i = 1; i <= height; i++) {
        for (j = 1; j <= width; j++)
            printf("%d", (i + j - 1) % 10);
        putchar('\n');
    }

    return 0;
}