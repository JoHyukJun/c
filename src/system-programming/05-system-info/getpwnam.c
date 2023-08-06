#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>


int main() {
    struct passwd *pw;

    pw = getpwnam("jo");
    printf("uid : %d\n", (int)pw->pw_uid);
    printf("home dir : %s\n", pw->pw_dir);
}