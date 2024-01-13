#include <stdio.h>


int main(void) {
    char str[] = "ABC\0DEF";

    printf("문자열 str 은 \"%s\" 입니다.\n", str);

    return 0;
}