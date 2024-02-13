/*
    - 다음은 바이너리 파일 "tm.bin" 에 저장된 struct tm 형 값을 읽어 들여 그 날짜와 시각을 화면에 출력하는 프로그램 일부다.
    - 파일 읽기에 실패했을 때는 경보음과 함께 화면에 "파일 "tm.bin" 를 열지 못했습니다." 라고 출력한다.
*/


#include <stdio.h>
#include <time.h>


int main(void) {
    FILE *fp;
    struct tm local;

    if ((fp = fopen("tm.bin", "rb"))) {
        fread(&local, sizeof(struct tm), 1, fp);

        fprintf(fp, "%d년 %d월 %d일 %d시 %d분 %d초 입니다.\n",
        local.tm_year + 1900,
        local.tm_mon + 1,
        local.tm_mday,
        local.tm_hour,
        local.tm_min,
        local.tm_sec);

        fclose(fp);
    }
    else {
        puts("\a파일 \"tm.bin\"를 열지 못했습니다.");
    }

    return 0;
}