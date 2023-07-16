#include <sys/time.h>
#include <stdio.h>


int main() {
    struct timeval tv;

    gettimeofday(&tv ,NULL);
    printf("time(sec): %d\n", (int)tv.tv_sec);
    printf("time(ms): %d\n", (int)tv.tv_usec);
}