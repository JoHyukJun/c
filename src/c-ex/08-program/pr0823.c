/*
    - 다음은 키보드로 입력한 정숫값을 읽어 들여 0, 1, 2 면 각각 '적색', '녹색', '청색' 이라고 출력하는 프로그램이다.
*/


#include <stdio.h>


int main(void) {
    enum RGB {Red, Green, Blue};
    int color;
    
    printf("0~2의 값: ");
    scanf("%d", &color);

    switch (color)
    {
    case Red:
        printf("적색");
        break;
    case Green:
        printf("녹색");
        break;
    case Blue:
        printf("청색");
        break;
    }

    return 0;
}