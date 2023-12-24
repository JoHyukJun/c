/*
    - 다음은 요소 개수가 n 개인 int 형 배열 a 의 보든 요소 값(값은 모두 양수)을 기호 문자 *를 세로로 나열한 아래 방향 그래프로 표시하는 프로그램이다.
    - 최초 행에 출력할 것은 첨자 최하위 자리의 수다.
*/


#include <stdio.h>


int main(void) {
    int n = 13;
    int i, j;
    int a[n];

    for (i = 0; i < n; i++)
        a[i] = i;

    int max = a[0];

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    for (i = 0; i < n; i++)
        printf("%d", i % 10);
    putchar('\n');

    for (i = 1; i <= max; i++) {
        for (j = 0; j < n; j++)
            if (a[j] >= i)
                putchar('*');
            else
                putchar(' ');
        putchar('\n');
    }

    return 0;
}