#include <stdio.h>

#define NAME_LEN 64


typedef struct student {
    char name[NAME_LEN];
    int height;
    float weight;
    long schols;
} Student;


void norm(Student *std) {
    if (std->height < 180) std->height = 180;
    if (std->weight > 80) std->weight = 80;
}

int main(void) {
    struct  student s1 = {"johj", 123, 123.1};

    printf("이름 = %s %p\n", s1.name, &s1.name);
    printf("키 = %d %p\n", s1.height, &s1.height);
    printf("몸무게 = %.1f %p\n", s1.weight, &s1.weight);
    printf("장학금 = %ld %p\n", s1.schols, &s1.schols);

    norm(&s1);

    printf("이름 = %s %p\n", s1.name, &s1.name);
    printf("키 = %d %p\n", s1.height, &s1.height);
    printf("몸무게 = %.1f %p\n", s1.weight, &s1.weight);
    printf("장학금 = %ld %p\n", s1.schols, &s1.schols);

    return 0;
}