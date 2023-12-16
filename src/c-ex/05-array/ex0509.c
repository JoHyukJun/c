#include <stdio.h>

#define NUMBER 80


int main(void) {
    int i, j, num;
    int score[NUMBER];
    int dist[11] = {0};
    int dist_max = 0;

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

    for (i = 0; i <= 10; i++) {
        if (dist[i] > dist_max)
            dist_max = dist[i];
    }

    for (i = dist_max; i >= 1; i--) {
        for (j = 0; j <= 10; j++) {
            if (dist[j] >= i) {
                printf(" * ");
            }
            else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (i = 0; i < 34; i++)
        putchar('-');
    putchar('\n');

    for (i = 0; i <= 10; i++)
        printf("%2d ", i * 10);
    putchar('\n');

    return 0;
}