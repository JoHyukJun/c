/*
    - 다음은 구구단 표를 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int i, j;
    
    printf("  |");

    for (i = 1; i <= 9; i++)
        printf("%3d", i);

    printf("\n--+-");

    for (i = 1; i <= 9; i++)
        printf("---");
    
    putchar('\n');

    for (i = 1; i <= 9; i++) {
        printf("%d |", i);

        for (j = 1; j <= 9; j++)
            printf("%3d", i * j);
        
        putchar('\n');
    }

    return 0;
}