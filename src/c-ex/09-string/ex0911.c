#include <stdio.h>


void del_digit(char s[]) {
    int i = 0, idx = 0;

    while (s[i]) {
        if (s[i] < '0' || s[i] > '9')
            s[idx++] = s[i];

        i++;
    }

    s[idx] = '\0';
}

int main(void) {
    char str[256];

    printf("문자열을 입력해주세요: ");
    scanf("%s", str);

    del_digit(str);

    puts("숫자 문자를 삭제했습니다.");
    printf("str=%s\n", str);

    return 0;
}