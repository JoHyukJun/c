#include <stdio.h>


int main(void)
{
    int month;

    printf("month: ");
    scanf("%d", &month);

    printf("%d val: ", month);

    switch (month)
    {
    case 3:
    case 4:
    case 5: puts("spring");
        break;
    case 6:
    case 7:
    case 8: puts("summer");
        break;
    case 9:
    case 10:
    case 11: puts("fall");
        break;
    case 12:
    case 1:
    case 2: puts("winter");
        breka;
    default: puts("invalid");
        break;
    }

    return 0;
}