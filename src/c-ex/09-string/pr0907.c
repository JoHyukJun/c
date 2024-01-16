/*
    - 다음은 문자열 s 에 포함된 숫자 문자의 개수를 반환하는 함수다.
*/


#include <stdio.h>


int str_digits_num(const char s[]) {
    int i, count = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9')
            count++;
    }

    return count;
}

int main(void) {
    char str[] = "AB123CD";

    printf("str: %s\n", str);

    printf("str_digits_num(str): %d\n", str_digits_num(str));

    return 0;
}