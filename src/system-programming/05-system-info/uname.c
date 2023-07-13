#include <sys/utsname.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    struct utsname uts;

    if (uname(&uts) == -1) {
        perror("unmae");
        exit(1);
    }

    printf("osname : %s\n", uts.sysname);
    printf("nodename : %s\n", uts.nodename);
    printf("release : %s\n", uts.release);
    printf("version : %s\n", uts.version);
    printf("machine : %s\n", uts.machine);
}