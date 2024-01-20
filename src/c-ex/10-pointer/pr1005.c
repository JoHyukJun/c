/*
    - 다음은 int 형 가인수 a 를 b 로 나눠 얻을 수 있는 몫과 나머지 (소수점 이하는 버림) 를 quot 가 가리키는 변수와 rem 이 가리키는 변수로 저장하는 함수다.
*/


#include <stdio.h>


void div(int a, int b, int *quot, int * rem) {
    *quot = a / b;
    *rem = a % b;
}

int main(void) {
    int quot = 0;
    int rem = 0;

    printf("quot: %d rem: %d\n", quot, rem);

    div(5, 4, &quot, &rem);

    printf("quot: %d rem: %d\n", quot, rem);

    return 0;
}