#include <sys/sysinfo.h>
#include <stdio.h>


int main() {
    struct sysinfo info;

    sysinfo(&info);

    printf("Total Ram: %ld\n", info.totalram);
    printf("Free Ram: %ld\n", info.freeram);
    printf("Num of Process: %d\n", info.procs);

    return 0;
}