#include <stdio.h>


int str_chr(const char *s, int ch) {
    int idx = 0;

    while(*s) {
        if (*s++ == ch)
            return idx;
        
        idx++;
    }

    return -1;
}

int main(void) {
    int idx;
    char str[256];
    char ch[10];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    printf("검색할 문자를 입력하세요: ");
    scanf("%s", ch);

    if ((idx = str_chr(str, ch[0])) == -1)
        printf("이 문자는 포함되지 않았습니다.\n");
    else
        printf("이 문자는 %d 번째에 들어 있습니다.\n", idx + 1);

    return 0;
}