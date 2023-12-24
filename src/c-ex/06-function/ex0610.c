#include <stdio.h>

#define NUMBER 5


int min_of(const int v[], int n) {
    int i;
    int min = v[0];

    for (i = 0; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }

    return min;
}

int main(void) {
    int i;
    int eng[NUMBER];
    int mat[NUMBER];
    int min_e, min_m;

    printf("%d명의 점수를 입력해주세요.\n", NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("[%d] eng: ", i + 1); scanf("%d", &eng[i]);
        printf("[%d] mat: ", i + 1); scanf("%d", &mat[i]);
    }

    min_e = min_of(eng, NUMBER);
    min_m = min_of(mat, NUMBER);

    printf("min eng: %d\n", min_e);
    printf("min mat: %d\n", min_m);

    return 0;
}