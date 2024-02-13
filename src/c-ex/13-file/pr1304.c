/*
    - 변수 x가 double 형이고 sizeof(double) 이 8 이라고 하자.
    - 변수 x의 값이 1.35일 때 fprintf(fp, "%f", x) 를 이용하면 스트림 fp 에는 (1) 바이트를 출력한다.
    - 한편 fwirte(x, sizeof(double), 1, fp) 를 ㅣ용하면 (2) 바이트를 출력한다.
    - (1): 8
    - (2): 8
*/


#include <stdio.h>


int main(void) {

    return 0;
}