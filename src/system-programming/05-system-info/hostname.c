#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    struct utsname uts;
    char buf[256];

    if (uname(&uts) == -1) {
        perror("uname");
        exit(1);
    }

    printf("uname host name: %s\n", uts.nodename);

    if (gethostname(buf, sizeof(buf)) == -1) {
        perror("gethostname");
        exit(1);
    }

    printf("gethostname host name: %s\n", buf);
}