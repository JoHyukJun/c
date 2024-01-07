#include <stdio.h>


int combination(int n, int r) {
    if (r == 0 || r == n) 
        return 1;
    else if (r == 1)
        return n;
    
    return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void) {
    int n, r;

    puts("서로 다른 n 개의 정수에서 r 개를 뽑아 만든 조합의 개수를 구합니다.");
    printf("n: "); scanf("%d", &n);
    printf("r: "); scanf("%d", &r);

    printf("combination:%d\n", combination(n, r));

    return 0;
}