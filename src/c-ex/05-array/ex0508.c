#include <stdio.h>

#define NUMBER 80


int main(void) {
    int i, j, num;
    int score[NUMBER];
    int dist[11] = {0};

    printf("len: ");

    do {
        scanf("%d", &num);

        if (num < 1 || num > NUMBER)
            printf("\a1~%d: ", NUMBER);
    } while(num < 1 || num > NUMBER);

    puts("input score.");

    for (i = 0; i < num; i++) {
        printf("%2d : ", i + 1);

        do {
            scanf("%d", &score[i]);

            if (score[i] < 0 || score[i] > 100)
                printf("\ainput 1 ~ 100.");
        } while (score[i] < 0 || score[i] > 100);

        dist[score[i] / 10]++;
    }

    puts("\n--- dist ---");

    for (i = 0; i <= 9; i++) {
        printf("%3d ~ %3d : ", i * 10, i * 10 + 9);

        for (j = 0; j < dist[i]; j++)
            putchar('*');
        putchar('\n');
    }

    printf("    100 : ");

    for (j = 0; j < dist[10]; j++)
        putchar('*');
    putchar('\n');

    return 0;
}