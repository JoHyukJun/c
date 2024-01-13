#include <stdio.h>


int str_char(const char s[], int c) {
    int i;

    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return i;

    return -1;
}

int main(void) {
    int no;
    char ch[10];

    printf("영문자를 입력해주세요: ");
    scanf("%s", ch);

    no = str_char("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstvwxyz", ch[0]);

    if (no >= 0 && no <= 25)
        printf("이는 대문자 %d 번째입니다.\n", no + 1);
    else if (no >= 26 && no <= 51)
        printf("이는 소문자 %d 번째입니다.\n", no - 25);
    else
        printf("이는 영문자가 압니다.\n");

    return 0;
}