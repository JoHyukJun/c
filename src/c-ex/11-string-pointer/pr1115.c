/*
    - 다음은 문자열 s 에 포함된 숫자 문자 '0'~'9'의 개수를 cnt[0] ~ cnt[9] 에 저장하는 함수다.
*/


#include <stdio.h>


void cnt_digit(const char *s, int cnt[]) {
    int i;

    for (i = 0; i < 10; i++) {
        *(cnt + i) = 0;
    }

    while (*s) {
        if (*s >= '0' && *s < '9') {
            cnt[*s - '0']++;
        }

        *s++;
    }
}

int main(void) {
    char s1[128] = "1232134124";
    int cnt[10];
    int i;

    printf("s1 = \"%s\"\n", s1);

    cnt_digit(s1, cnt);

    for (i = 0; i < 10; i++) {
        printf("cnt[%d] = %d\n", i, cnt[i]);
    }

    return 0;
}