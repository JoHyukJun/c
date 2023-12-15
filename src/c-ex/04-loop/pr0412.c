/*
    - 다음은 읽어 들인 정숫값의 개수만큼 '온고지신'이라고 표시하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int i, no;

    printf("input 1 number.");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
        printf("온고지신");
    putchar('\n');

    return 0;
}