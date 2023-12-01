#include <stdio.h>


int main(void)
{
    int no;

    printf("no: ");
    scanf("%d", &no);

    switch (no % 2)
    {
    case 0: puts("even");
        break;
    
    case 1: puts("odd");
        break;
    }

    return 0;
}