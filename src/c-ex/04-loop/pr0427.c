/*
    - 다음은 int 형 정수 n 의 값을 15자리 넓이로 오른쪽 정렬해 출력하는 프로그램이다.
    - int 형으로 표한할 수 있는 범위는 개발환경에 따라 다르므로, 반드시 int 형으로 1234567890 을 표현할 수 있다고는 할 수 없다.
*/


#include <stdio.h>


int main(void) {
    int n, i;

    puts("input 1 number.");
    scanf("%d", &n);

    int d = (n < 0) ? 1 : 0;
    int x = (n >= 0) ? n : -n;

    while (x > 0) {
        d++;
        x /= 10;
    }

    for (i = 0; i < d; i++)
        putchar(' ');

    printf("%d", n);

    return 0;
}