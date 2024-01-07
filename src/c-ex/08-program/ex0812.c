#include <stdio.h>


int main(void) {
    int i, j, ch;
    int cnt[10] = {0};

    while ((ch = getchar()) != EOF)
    {
        if (ch >= '0' && ch <= '9')
            cnt[ch - '0']++;
    }

    puts("숫자 문자의 등장 횟수");

    for (i = 0; i < 10; i++) {
        printf("%d: ", i);

        for (j = 0; j < cnt[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}