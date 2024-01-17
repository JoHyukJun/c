/*
    - 다음은 문자열 s 에 포함된 문자 c 의 첨자 (한 개도 없을 때는 -1) 를 반환하는 함수다.
    - 문자 c 가 여러 개 포함된 경우 str_idx 는 가장 앞쪽 첨자를 반환하고, str_ridx 는 가장 뒤쪽 첨자를 반환하는 것으로 한다.
*/


#include <stdio.h>


int str_idx(const char s[], int c) {
    int i = 0;

    while(s[i]) {
        if (s[i] == c)
            return i;

        i++;
    }

    return -1;
}

int str_idx_2(const char s[], int c) {
    int i = 0, idx = -1;
    
    while(s[i]) {
        if (s[i] == c)
            idx = i;

        i++;
    }

    return idx;
}

int main(void) {
    char str1[] = "ABCBC";

    printf("str1: %s\n", str1);

    printf("str_idx(str1, 'A'): %d\n", str_idx(str1, 'A'));
    printf("str_idx(str1, 'E'): %d\n", str_idx(str1, 'E'));
    printf("str_idx(str1, 'B'): %d\n", str_idx(str1, 'B'));

    return 0;
}