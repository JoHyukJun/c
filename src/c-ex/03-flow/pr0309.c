/*
    - 다음은 w값이 0, 1, 2면 "맑음", "비", "흐림" 이라고 표시하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int w;

    puts("input 1 number.");
    printf("w: ");
    scanf("%d", &w);

    switch (w)
    {
    case 0: puts("맑음");
        break;
    case 1: puts("비");
        break;
    case 2: puts("흐림");
        break; 
    }

    return 0;
}