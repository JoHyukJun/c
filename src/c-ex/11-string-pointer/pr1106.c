/*
    - 다음은 문자열의 길이를 구하거나 문자열을 복사 또는 연결하는 프로그램 일부다.
*/


#include <stdio.h>
#include <string.h>


int main(void) {
    char s1[10], s2[10], s3[10];

    strcpy(s1, "ABC");

    printf("s1 의 길이는 %lu\n", strlen(s1));

    printf("s1을 복사한 후의 s2는 %s\n", strcpy(s2, s1));

    printf("복사 후의 s3은 %s\n", strcpy(s3, strcpy(s2, s1)));

    printf("s2를 연결한 후의 s1은 %s\n", strcat(s1, s2));

    return 0;
}