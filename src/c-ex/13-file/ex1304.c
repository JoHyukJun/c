#include <stdio.h>
#include <string.h>

#define NAME_LEN 100


int main(void) {
    FILE *fp;
    int i;
    char name[NAME_LEN];
    double height;
    double weight;

    if ((fp = fopen("test.txt", "w")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        for (i = 0; ;i++) {
            int flag;
            printf("%d 명째의 데이터를 입력하겠습니까? (예...1/종료...0)\n", i + 1);
            scanf("%d", &flag);

            if (flag == 0) break;

            printf("이름: "); scanf("%s", name);
            printf("키: "); scanf("%lf", &height);
            printf("몸무게: "); scanf("%lf", &weight);

            fprintf(fp, "%s %f, %f\n", name, height, weight);
        }

        fclose(fp);
    }

    return 0;
}