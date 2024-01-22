#include <stdio.h>


char *str_copy(char *d, const char *s) {
    char *t = d;

    while (*d++ = *s++);

    return t;
}

int main(void) {
    char str[128] = "ABC";
    char tmp[128];

    printf("str \"%s\"\n", str);

    printf("복사할 것은: ");
    scanf("%s", tmp);

    puts("복사했습니다.");
    printf("str \"%s\"\n", str_copy(str, tmp));

    return 0;
}