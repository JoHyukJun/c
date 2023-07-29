#include <stdio.h>


int main() {
    char *pszParam = "hello world\n";
    printf(pszParam);
    printf("hello world\n");

    pszParam = "nullnull != null";
    printf(pszParam);

    return 0;
}