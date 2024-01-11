/*
    - 다음은 경고음을 발생시키고 문자열 str 을 출력하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define puts_alert2(str) ( putchar('\a'), puts(str))


int main(void) {
    puts_alert2("TEST");
    
    return 0;
}