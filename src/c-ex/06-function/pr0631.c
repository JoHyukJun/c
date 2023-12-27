/*
    - 앞 문제의 함수 val 을 호출해서 테스트하는 main 함수를 작성하라.
*/


#include <stdio.h>


int val(int no) {
    static int v;
    int temp = v;

    v = no;

    return temp;
}

int main(void) {
    printf("val(3): %d\n", val(3));
    printf("val(-1): %d\n", val(-1));
    printf("val(4): %d\n", val(4));
    printf("val(5): %d\n", val(5));
    printf("val(0): %d\n", val(0));

    return 0;
}