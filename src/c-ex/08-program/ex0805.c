#include <stdio.h>

#define NUMBER 5


void bsort(int a[], int n) {
    int i, j;

    for (i = n; i > 0; i--) {
        for (j = 1; j < i; j++) {
            if (a[j - 1] > a[j]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

int main(void) {
    int i;
    int height[NUMBER];

    printf("%d명의 키를 입력해주세요.\n", NUMBER);
    for (i = 0; i < NUMBER; i++) {
        printf("%2d번: ", i + 1);
        scanf("%d", &height[i]);
    }

    bsort(height, NUMBER);

    puts("오름차순으로 정렬했습니다.");

    for (i = 0; i < NUMBER; i++) {
        printf("%2d번: %d\n", i + 1, height[i]);
    }

    return 0;
}