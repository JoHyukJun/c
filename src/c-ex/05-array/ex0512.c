#include <stdio.h>


int main(void) {
    int i, j, k;
    int score[2][4][3] = {
        {{91, 63, 78}, {67, 72, 23}, {32, 12, 23}, {54, 65, 76}},
        {{23, 54, 65}, {12, 34, 76}, {56, 34, 75}, {23, 45, 77}},
    };

    int sum[4][3];

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            sum[i][j] = score[0][i][j] + score[1][i][j];
        }
    }

    for (i = 0; i < 2; i++) {
        printf("%d score\n", i + 1);

        for (j = 0; j < 4; j++) {
            for (k = 0; k < 3; k++) {
                printf("%4d", score[i][j][k]);
            }
            putchar('\n');
        }
    }

    puts("sum");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", sum[i][j]);
        }
        putchar('\n');
    }

    return 0;
}