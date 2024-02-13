/*
    - 다음은 지금의 날짜와 시각을 (연, 월, 일, 시, 분, 초를 10진수로) 텍스트 파일 "tm.txt" 로 쓰는 프로그램의 일부다.
    - 파일 읽기에 실패했을 때는 경보음과 함께 화면에 "파일 "tm.txt" 를 열지 못했습니다." 라고 출력한다.
*/


#include <stdio.h>
#include <time.h>


int main(void) {
    FILE *fp;
    time_t current = time(NULL);
    struct tm *local = localtime(&current);

    if ((fp = fopen("tm.txt", "w")) == NULL) {
        puts("\a파일 \"tm.txt\"를 열지 못했습니다.");
    }
    else {
        fprintf(fp, "%d년 %d월 %d일 %d시 %d분 %d초 입니다.\n",
        local->tm_year + 1900,
        local->tm_mon + 1,
        local->tm_mday,
        local->tm_hour,
        local->tm_min,
        local->tm_sec);

        fclose(fp);
    }

    return 0;
}