#include <time.h>
#include <stdio.h>


/*
    - size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);
        - char *s
            - 출력할 시간 정보를 저장할 배열 주소
        - size_t max
            - 배열 s의 크기
        - const char *format
            - 출력 형식을 지정한 문자열
        - const struct tm *tm
            - 출력할 시간 정보를 저장한 구조체 주소
*/
char *output[] = {"%x %X", "%G y %m m %d d %U w %H:%M", "%r"};

int main() {
    struct tm *tm;
    int n;
    time_t timep;
    char buf[256];

    time(&timep);
    tm = localtime(&timep);

    for (n = 0; n < 3; n++) {
        strftime(buf, sizeof(buf), output[n], tm);
        printf("%s = %s\n", output[n], buf);
    }
}