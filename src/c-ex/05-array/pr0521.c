/*
    - 다음은 요소 개수가 NUMBER 인 배열 point 의 선언 (여기서 NUMBER 는 10이라고 함) 과 이 배열의 모든 요소에 0 이상 100 이하의 값을 읽어 들이는 (범위 밖의 값이 들어오면 재입력 요청) 프로그램 일부다.
*/


#include <stdio.h>

#define NUMBER 10


int main(void) {
    int point[NUMBER];
    int i;

    puts("0 ~ 100 사이의 값을 입력해주세요.");

    for (i = 0; i < NUMBER; i++) {
        while (1)
        {
            printf("point[%d]: ", i);
            scanf("%d", point[i]);

            if (point[i] >= 0 && point[i] <= 100)
                break;
            puts("\a범위 밖입니다.");
        }
    }

    return 0;
}