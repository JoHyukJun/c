/*
    - 변수 x 가 int 형이고 sizeof(int) 가 2 라고 하자. 변수 x 의 값이 357 일 때 fprintf(fp, "%d", x) 를 이용하면 스트림 fp 에는 (1) 바이트를 출력한다.
    - 한편 fwrite(&x, sizeof(int), 1, fp) 를 이용하면 (2) 바이트를 출력한다.
    - (1): 3
    - (2): 2
*/


#include <stdio.h>


int main(void) {

    return 0;
}