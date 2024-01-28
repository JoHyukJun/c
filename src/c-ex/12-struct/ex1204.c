#include <stdio.h>
#include <string.h>

#define NUMBER 5
#define NAME_LEN 64


typedef struct {
    char name[NAME_LEN];
    int height;
    float weight;
    long schols;
} Student;


void swap_Student(Student *x, Student *y) {
    Student temp = *x;
    *x = *y;
    *y = temp;
}

void sort_by_height(Student a[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j - 1].height > a[j].height) {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

void sort_by_name(Student a[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j - 1].name > a[j].name) {
                swap_Student(&a[j - 1], &a[j]);
            }
        }
    }
}

int main(void) {
    int i;
    int sort_type;
    Student std[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("%d 번째 학생\n", i + 1);

        printf("이름: "); scanf("%s", std[i].name);
        printf("키: "); scanf("%d", &std[i].height);
        printf("몸무게: "); scanf("%f", &std[i].weight);
        printf("장학금: "); scanf("%ld", &std[i].schols);
    }

    for (i = 0; i < NUMBER; i++) {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    printf("어떤 순서로 정렬할까요? [0]_키순 [1]_이름순: ");
    scanf("%d", &sort_type);

    switch (sort_type)
    {
    case 0:
        sort_by_height(std, NUMBER);
        break;
    case 1:
        sort_by_name(std, NUMBER);
        break;
    }

    for (i = 0; i < NUMBER; i++) {
        printf("%-8s %6d%6.1f%7ld\n", std[i].name, std[i].height, std[i].weight, std[i].schols);
    }

    return 0;
}