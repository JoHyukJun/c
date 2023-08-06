#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>


int main() {
    struct passwd *pw;

    pw = getpwuid(getuid());
    printf("uid : %d\n", (int)pw->pw_uid);
    printf("login name : %s\n", pw->pw_name);
}