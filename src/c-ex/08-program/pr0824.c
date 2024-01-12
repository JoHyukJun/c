/*
    - 다음은 키보드로 입력한 문자를 화면에 출력함과 동시에 읽어 들인 문자 수, 줄 바꿈 수, 각각의 숫자 문자 수를 세어 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    int i;
    int ch;
    int c_count = 0;
    int n_count = 0;
    int cnt[10] = {0};

    while ((ch = getchar()) != EOF) {
        c_count++;

        if (ch == '\n')
            n_count++;
        else if (ch >= '0' && ch <= '9')
            cnt[ch - '0']++;
    }

    printf("문자 수: %d\n", c_count);
    printf("줄 바꿈 수: %d\n", n_count);

    puts("숫자 문자의 등장 횟수");

    for (i = 0; i < 10; i++) {
        printf("'%d' : %d\n", i, cnt[i]);
    }
    
    return 0;
}