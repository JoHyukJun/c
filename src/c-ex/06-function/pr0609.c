/*
    - 다음은 모두 a 이상 b 이하의 정수를 읽어 들여 그 값을 반환하는 함수다.
    - 올바른 범위 내의 값을 읽어 들일 때까지 반복.
*/


#include <stdio.h>


int scan_a_to_b(int a, int b) {
    int tmp;

    do {
        scanf("%d", &tmp);
    } while (tmp < a || tmp > b);

    return tmp;
}

int scan_a_to_b2(int a, int b) {
    int tmp;

    while (1) {
        scanf("%d", &tmp);

        if (tmp >= a && tmp <= b)
            return tmp;
    }
}

int main(void) {
    printf("%d\n", scan_a_to_b(3, 6));
    printf("%d\n", scan_a_to_b2(3, 6));

    return 0;
}