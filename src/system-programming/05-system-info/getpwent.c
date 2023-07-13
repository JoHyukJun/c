#include <pwd.h>
#include <stdio.h>


int main() {
    struct passwd *pw;
    int n;

    for (n = 0; n < 3; n++) {
        pw = getpwent();
        printf("uid : %d\n", (int)pw->pw_uid);
    printf("login name : %s\n", pw->pw_name);
    }
}