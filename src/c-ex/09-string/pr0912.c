/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        ABCDEFG
        ABCDEFG
        ABCD
          ABCDEFG
        ABCDEFG 
*/


#include <stdio.h>


int main(void) {
    char str[] = "ABCDEFG";

    printf("%s\n", str);
    printf("%4s\n", str);
    printf("%.4s\n", str);
    printf("%9s\n", str);
    printf("%-9s\n", str);

    return 0;
}