/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        "ABC"
        'ABC'
        'ABC'
        ""
        75
*/


#include <stdio.h>


int main(void) {
    printf("\"ABC\"\n");
    printf("\'ABC\'\n");
    printf("'ABC'\n");
    putchar('\"');
    putchar('"');
    putchar('\n');
    putchar(7 + '0');
    printf("%d\n", '5' - '0');
    
     return 0;
}