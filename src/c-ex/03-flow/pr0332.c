/*
    - 다음 프로그램에서 틀린 곳을 찾아라.
*/


#include <stdio.h>


int main(void) {
    int no;

    printf("input 1 number.");
    /*
    scan("%d", no);
    */
    scanf("%d", &no);

    if (no > 0) {
        switch (no % 2)
        {
        case 0:
            puts("even");
            break;
        case 1:
            puts("odd");
            break;
        }
    }

    return 0;
}