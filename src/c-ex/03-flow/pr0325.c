/*
    - 다음의 switch 는 int 형 변수 no 값이 1이면 (1) 이라고 출력하고, 2라면 (2) 이라고 출력하고, 3이면 (3) 이라고 출력하고, 4라면 (4) 이라고 출력한다.
    - (1): C
    - (2): B
    - (3): AB
    - (4): C
*/


#include <stdio.h>


int main(void) {
    int no;

    puts("input 1 number.");
    printf("no: ");
    scanf("%d", &no);

    switch (no)
    {
    case 3:
        printf("A");
    case 2:
        printf("B");
        break;
    case 1:
    default:
        printf("C");
        break;
    }

    return 0;
}