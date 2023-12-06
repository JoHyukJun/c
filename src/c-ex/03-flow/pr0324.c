/*
    - 다음은 n 값을 3으로 나눴을 때 나눠떨어지는지, 나머지가 1이 되는지, 2가 되는지 판정해서 출력하는 프로그램의 일부다.
*/


#include <stdio.h>


int main(void) {
    int n;

    puts("input 1 number.");
    printf("n: ");
    scanf("%d", &n);

    if (n % 3 == 0)
        puts("mod 0");
    else if (n % 3 == 1)
        puts("mod 1");
    else
        puts("mod 2");

    int mod;

    mod = n % 3;

    if (mod != 0)
        printf("mod %d\n", mod);
    else
        puts("mod 0");

    switch (mod)
    {
    case 0:
        puts("mod 0");
        break;
    case 1:
        puts("mod 1");
        break;
    case 2:
        puts("mod 2");
        break;
    default:
        break;
    }

    return 0;
}