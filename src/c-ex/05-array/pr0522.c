/*
    - 다음은 앞 문제의 프로그램 일부로, 읽어 들인 배열 point 의 모든 요수 값(0 이상 100 이하의 값) 을 이용해 다음과 같은 변수와 배열로 값을 대입해서 출력하는 프로그램 일부다.
    - count 는 모든 요소를 0 으로 초기화한 요소 개수 4인 배열이고, idx 는 4행 NUMBER 열인 2차원 배열이다.
    - count[0] - 탈락(값이 60 미만) 인 요소 개수
    - count[1] - 가능(값이 60 이상 69 미만) 인 요소 개수
    - count[2] - 양호(값이 70 이상 79 미만) 인 요소 개수
    - count[3] - 우수(값이 80 이상 100 미만) 인 요소 개수
    - idx[0][0] ~ idx[0][count[0] - 1] - 탈락 요소의 첨자
    - idx[1][0] ~ idx[1][count[1] - 1] - 가능 요소의 첨자
    - idx[2][0] ~ idx[2][count[2] - 1] - 양호 요소의 첨자
    - idx[3][0] ~ idx[3][count[3] - 1] - 우수 요소의 첨자
*/


#include <stdio.h>

#define NUMBER 10


int main(void) {
    int point[NUMBER];
    int count[4] = {0};
    int idx[4][NUMBER];
    int i;

    puts("0 ~ 100 사이의 값을 입력해주세요.");

    for (i = 0; i < NUMBER; i++) {
        while (1)
        {
            printf("point[%d]: ", i);
            scanf("%d", &point[i]);

            if (point[i] >= 0 && point[i] <= 100)
                break;
            puts("\a범위 밖입니다.");
        }
    }

    for (i = 0; i < NUMBER; i++) {
        int grade = 0;

        if (point[i] >= 80)
            grade = 3;
        else if (point[i] >= 70)
            grade = 2;
        else if (point[i] >= 60)
            grade = 1;

        idx[grade][count[grade]++] = i;
    }

    printf("탈락: "); for (i = 0; i < count[0]; i++) putchar('*'); putchar('\n');
    printf("가능: "); for (i = 0; i < count[1]; i++) putchar('*'); putchar('\n');
    printf("양호: "); for (i = 0; i < count[2]; i++) putchar('*'); putchar('\n');
    printf("우수: "); for (i = 0; i < count[3]; i++) putchar('*'); putchar('\n');

    return 0;
}