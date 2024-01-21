/*
    - 다음 프로그램 일부의 실행 결과를 나타내라.
    ->
        p == v              ->1
        p != &v[0]          ->0
        p == &v[1]          ->0
        p == &v[2]          ->0
        &v[1] - &v[0]       ->1
        &v[2] - &v[0]       ->2
*/


#include <stdio.h>


int main(void) {
    int v[10], *p = v;

    printf("p == v              ->%d\n", p == v);
    printf("p != &v[0]          ->%d\n", p != &v[0]);
    printf("p == &v[1]          ->%d\n", p == &v[1]);
    printf("p == &v[2]          ->%d\n", p == &v[2]);
    printf("&v[1] - &v[0]       ->%d\n", &v[1] - &v[0]);
    printf("&v[2] - &v[0]       ->%d\n", &v[2] - &v[0]);

    return 0;
}