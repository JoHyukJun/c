/*
    - 다음은 month 값에 따라 계절을 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int month;

    puts("input 1 number.");
    printf("month: ");
    scanf("%d", &month);

    if (month >= 3 && month <= 5)
        printf("%d월은 봄입니다.\n", month);
    else if (month >= 6 && month <= 8)
        printf("%d월은 여름입니다.\n", month);
    else if (month >= 9 && month <= 11)
        printf("%d월은 가을입니다.\n", month);
    else if (month == 1 || month == 2 || month == 12)
        printf("%d월은 겨울입니다.\n", month);
    else
        printf("%d월은 없습니다.\n", month);

    if (month < 1 || month > 12)
        printf("%d월은 없습니다.\n", month);
    else if (month <= 2 || month == 12)
        printf("%d월은 겨울입니다.\n", month);
    else if (month >= 9 && month <= 11)
        printf("%d월은 가을입니다.\n", month);
    else if (month >= 6 && month <= 8)
        printf("%d월은 여름입니다.\n", month);
    else
        printf("%d월은 봄입니다.\n", month);

    printf("%d월은 ", month);

    if (month < 1 || month > 12)
        printf("없습니다.\n");
    else
    {
        int x = month / 3;

        switch (x)
        {
        case 1:
            puts("봄입니다.");
            break;
        case 2:
            puts("여름입니다.");
            break;
        case 3:
            puts("가을입니다.");
            break;
        default:
            puts("겨울입니다.");
            break;
        }
    }

    return 0;
}