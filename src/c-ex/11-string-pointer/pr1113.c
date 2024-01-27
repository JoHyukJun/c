/*
    - 다음은 문자열 s2 를 s1 로 복사한 다음, 전달받은 s1 과 똑같은 값을 반호나하는 함수다.
    - 문자열 s2 의 길이가 n 이상이면 n 문자까지 복사하고, n 부터 짧으면 나머지는 널 문자로 채운다.
*/


#include <stdio.h>


char *str_ncpy(char *s1, const char *s2, int n) {
    char *tmp = s1;

    while (n > 0) {
        n--;

        if (!(*s1++ = *s2++))
            break;
    }

    while (n--) {
        *s1++ = '\0';
    }

    return tmp;
}

int main(void) {
    char s1[128];
    char *s2 = "123123";
    char *res;

    res = str_ncpy(s1, s2, 3);

    printf("s1 = \"%s\"\n", s1);
    printf("res = \"%s\"\n", res);

    return 0;
}