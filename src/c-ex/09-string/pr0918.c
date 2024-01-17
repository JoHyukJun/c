/*
    - 다음은 문자열 s1 안에 문자열 s2 가 포함돼 있으면 그 첫 번쨰 첨자를 반환하는 함수다.
    - 여러 개 있을 때는 더 앞쪽에 있는 것으로 하고, 한 개도 없을 때는 -1 로 한다.
    - 예를 들어 s1 이 "ABCAICCAI" 고 s2 가 "CAI" 면 2를 반환한다.
*/


#include <stdio.h>


int strstr_idx(const char s1[], const char s2[]) {
    int i;
    
    if (s2[0] == '\0')
        return -1;

    for (i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[0]) {
            int j = 0;

            do {
                if (s2[++j] == '\0')
                    return i;
            } while (s1[i + j] == s2[j]);
        }
    }

    return -1;
}

int main(void) {
    char str1[] = "ABCBC";
    char str2[] = "BC";

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    printf("strstr_idx(str1, str2): %d\n", strstr_idx(str1, str2));

    return 0;
}