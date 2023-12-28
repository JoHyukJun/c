#include <stdio.h>
#include <limits.h>


int main(void) {
    printf("char                :   %u bytes\n", (unsigned)sizeof(char));
    printf("short               :   %u bytes\n", (unsigned)sizeof(short));
    printf("int                 :   %u bytes\n", (unsigned)sizeof(int));
    printf("long                :   %u bytes\n", (unsigned)sizeof(long));

    return 0;
}