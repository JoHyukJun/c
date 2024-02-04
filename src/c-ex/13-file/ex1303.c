#include <stdio.h>
#include <string.h>

#define NUM_MAX 50
#define NAME_LEN 100


typedef struct {
    char name[NAME_LEN];
    double height;
    double weight;
} Human;


void swap_Human(Human *x, Human *y) {
    Human temp = *x;
    *x = *y;
    *y = temp;
}

void sort_by_height(Human a[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j - 1].height > a[j].height) {
                swap_Human(&a[j - 1], &a[j]);
            }
        }
    }
}

int main(void) {
    FILE *fp;
    int i, j;
    int number = 0;
    char name[NAME_LEN][NUM_MAX];
    double height[NUM_MAX];
    double weight[NUM_MAX];
    double hsum = 0.0;
    double wsum = 0.0;

    Human data[NUM_MAX];

    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        for (i = 0; i < NUM_MAX; i++) {
            if (fscanf(fp, "%s%lf%lf",
            name[number], &height[number], &weight[number]) != 3) {
                break;
            }

            hsum += height[number];
            wsum += weight[number];
            number++;
        }

        for (i = 0; i < number - 1; i++) {
            for (j = number - 1; j > 1; j--) {
                if (height[j - 1] > height[j]) {
                    char tn[NAME_LEN];
                    double td;

                    strcpy(tn, name[j]);
                    strcpy(name[j], name[j - 1]);
                    strcpy(name[j - 1], tn);

                    td = height[j];
                    height[j] = height[j - 1];
                    height[j - 1] = td;

                    td = weight[j];
                    weight[j] = weight[j - 1];
                    weight[j - 1] = td;
                }
            }
        }

        for (i = 0; i < number; i++) {
            printf("%-10s %5.1f %5.1f\n", name[i], height[i], weight[i]);
        }

        printf("-------------------------\n");
        printf("평균       %5.1f %5.1f\n", hsum / number, wsum / number);
        fclose(fp);
    }

    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        for (i = 0; i < NUM_MAX; i++) {
            if (fscanf(fp, "%s%lf%lf",
            name[number], &height[number], &weight[number]) != 3) {
                break;
            }

            hsum += height[number];
            wsum += weight[number];
            number++;
        }

        sort_by_height(data, number);

        for (i = 0; i < number; i++) {
            printf("%-10s %5.1f %5.1f\n", name[i], height[i], weight[i]);
        }

        printf("-------------------------\n");
        printf("평균       %5.1f %5.1f\n", hsum / number, wsum / number);
        fclose(fp);
    }

    return 0;
}