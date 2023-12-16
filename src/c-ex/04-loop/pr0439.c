/*
    - 다음은 9부터 1까지의 정숫값을 1문자씩 밀어 쓰면서 출력(9는 1행째, 8은 2행째, ... , 1은 9행째에 출력) 하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int i, j;

    for (i = 9; i > 0; i--) {
        for (j = 1; j <= 9 - i; j++) {
            putchar(' ');
        }
        printf("%d\n", i);
    }

    return 0;
}