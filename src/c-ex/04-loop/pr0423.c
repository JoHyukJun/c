/*
    - 다음은 음이 아닌 정수를 연속으로 읽어 들여 각 값을 제곱한 합을 출력하는 프로그램의 일부다.
    - 정수를 읽어 들일 때 음의 정수를 입력하는 단계에서 종료하고 그 수의 제곱은 더하지 않는다.
*/


#include <stdio.h>


int main(void) {
    int i = 0;
    int sum = 0;
    int no;

    puts("input integer number.");

    do {
        printf("No.%d : ", ++i);
        scanf("%d", &no);

        if (no > 0)
            sum += no * no;
    } while (no > 0);

    printf("sum: %d\n", sum);

    return 0;
}