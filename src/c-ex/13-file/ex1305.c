#include <stdio.h>
#include <time.h>


char data_file[] = "test.txt";


void get_data(void) {
    FILE *fp;

    if ((fp = fopen(data_file, "r")) == NULL) {
        printf("이 프로그램을 처음 실행하는군요.\n");
    }
    else {
        int year, month, day, h, m, s;
        char feeling[2048];

        fscanf(fp, "%d%d%d%d%d%d", &year, &month, &day, &h, &m, &s);
        fscanf(fp, "%s", feeling);

        printf("이전 실행은 %d년 %d월 %d일 %d시 %d분 %d초 였고 기분은 '%s'였습니다.\n",
        year, month, day, h, m, s, feeling);

        fclose(fp);
    }
}

void put_data(const char *feeling) {
    FILE *fp;
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);

    if ((fp = fopen(data_file, "w")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fprintf(fp, "%d %d %d %d %d %d\n",
        timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday,
        timer->tm_hour, timer->tm_min, timer->tm_sec);

        fprintf(fp, "%s\n", feeling);

        fclose(fp);
    }
}

int main(void) {
    char feeling[2048];

    get_data();

    printf("지금의 기분은: ");
    scanf("%s", feeling);

    put_data(feeling);

    return 0;
}