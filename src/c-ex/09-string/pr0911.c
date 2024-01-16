/*
    - 다음은 문자열 s 가 회문(앞에서 읽든 뒤에서 읽든 같은 문자열) 이면 1을 반환하고 그렇지 않으면 0 을 반환하는 함수다.
*/


#include <stdio.h>


int is_palindrome(const char s[]) {
    int i, len = 0;

    while (s[len])
        len++;

    for (i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1])
            return 0;
    }

    return 1;
}

int main(void) {
    char str[] = "test";
    char str2[] = "ABABA";

    printf("str: %s\n", str);

    printf("is_palindrome(str): %d\n", is_palindrome(str));

    printf("str2: %s\n", str2);

    printf("is_palindrome(str2): %d\n", is_palindrome(str2));

    return 0;
}