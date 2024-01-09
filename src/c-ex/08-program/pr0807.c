/*
    - 다음은 x 와 y 중 작은 쪽의 값과 큰 쪽의 값을 구하는 함수 형식 매크로다.
*/


#include <stdio.h>

#define min_of(x, y) (((x) < (y)) ? x : y)
#define max_of(x, y) (((x) > (y)) ? x : y)


int main(void) {
    printf("min_of(3, 4): \t%d\n", min_of(3, 4));
    printf("min_of(4, 3): \t%d\n", min_of(4, 3));
    printf("max_of(3, 4): \t%d\n", max_of(3, 4));
    printf("max_of(4, 3): \t%d\n", max_of(4, 3));

    return 0;
}