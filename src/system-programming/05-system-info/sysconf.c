#include <unistd.h>
#include <stdio.h>


int main() {
    printf("arg max: %ld\n", sysconf(_SC_ARG_MAX));
    printf("clock tick: %ld\n", sysconf(_SC_CLK_TCK));
    printf("max open file: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("max login name length: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
}