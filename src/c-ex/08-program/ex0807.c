#include <stdio.h>


enum month {
    January = 1, February, March, April, May, June, July, August, September, October, November, December
};

void print_season(enum month month) {
    switch (month)
    {
    case March:
    case April:
    case May:
        printf("Spring");
        break;
    case June:
    case July:
    case August:
        printf("Summer");
        break;
    case September:
    case October:
    case November:
        printf("Fall");
        break;
    case December:
    case January:
    case February:
        printf("Winter");
        break;
    
    default:
        printf("INVALID SEASON VALUE");
        break;
    }
}

enum month select_month(void) {
    int tmp;

    do {
        printf("Month: ");
        scanf("%d", &tmp);
    } while (tmp < January || tmp > December);

    return tmp;
}

int main(void) {
    enum month your_month;

    printf("Input your birth month.\n");
    your_month = select_month();

    printf("Your birth season: ");
    print_season(your_month);
    putchar('\n');

    return 0;
}