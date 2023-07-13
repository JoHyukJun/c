#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main() {
    gid_t gid, egid;

    gid = getgid();
    egid = getegid();

    printf("gid = %d, egid = %d\n", (int)gid, (int)egid);
}