#include <unistd.h>
#include <stdio.h>


/*
    - long pathconf(const char *path, int name);
        - pathconf() 함수는 path에 지정한 파일이나 디렉터리와 관련해 설정된 자원값이나 옵션값을 리턴
        - name에는 검색할 정보를 나타내는 상수를 지정
        - _PC_LINK_MAX
        - 파일에 가능한 최대 링크 수
        - _PC_NAME_MAX
        - 파일명의 최대 길이를 바이트 크기로 표시
        - _PC_PATH_MAX
        - 상대 경로명의 최대 길이를 바이크 크기로 표시
*/
int main() {
    printf("link max: %ld\n", pathconf(".", _PC_LINK_MAX));
    printf("name max: %ld\n", pathconf(".", _PC_NAME_MAX));
    printf("path max: %ld\n", pathconf(".", _PC_PATH_MAX));
}