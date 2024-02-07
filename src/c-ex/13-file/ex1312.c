#include <stdio.h>
#include <time.h>


char data_file[] = "text.txt";


void get_data(void) {
    FILE *fp;
    struct tm local;

    if ((fp = fopen(data_file, "rb")) == NULL) {
        printf("이 프로그램을 처음 실행하는군요.\n");
    }
    else {
        fread(&local, sizeof(struct tm), 1, fp);

        printf("이전 실행은 %d년 %d월 %d일 %d시 %d분 %d초 였습니다.\n",
        local.tm_year + 1900, local.tm_mon + 1, local.tm_mday,
        local.tm_hour, local.tm_min, local.tm_sec);

        fclose(fp);
    }
}

void put_data(void) {
    FILE *fp;
    time_t current = time(NULL);
    struct tm *timer = localtime(&current);

    if ((fp = fopen(data_file, "wb")) == NULL) {
        printf("\a파일을 열 수 없습니다.\n");
    }
    else {
        fwrite(timer, sizeof(struct tm), 1, fp);

        fclose(fp);
    }
}

int main(void) {
    get_data();

    put_data();

    return 0;
}