/*
    - 다음 프로그램 일부 중 잘못된 곳을 찾아라.
*/


#include <stdio.h>


int main(void) {
    /*
        - 문자열을 배열로 선언시 변수에 재할당 불가능하여 포인터형으로 선언.
    */
    char *s;

    s = "ABC";
    /*
        - 문자열 출력을 위해 %s 로 할당.
    */
    printf("%s\n", s);

    return 0;
}