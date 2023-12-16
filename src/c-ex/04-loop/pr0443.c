/*
    - 다음 프로그램에서 틀린 곳을 찾아라.
*/


#include <stdio.h>


int main(void) {
    /*
        - switch 는 키워드라 사용 불가
    */
    int i, switch_;

    printf("input 1 number.");
    scanf("%d", &switch_);

    for (i = 0; i < switch_; i++)
        printf("%d", switch_);

    return 0;
}