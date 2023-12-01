#include <stdio.h>


int main(void)
{
    int point;

    puts("input 2 number.");
    printf("point : ");
    scanf("%d", &point);

    if (point < 0 || point > 100)
        puts("invalid score");
    else if (point <= 50)
        puts("disable");
    else if (point <= 69)
        puts("able");
    else if (point <= 79)
        puts("positive")
    else
        puts("exl");
        
    return 0;
}