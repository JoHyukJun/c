#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>


int main() {
    struct passwd *pw;
    char i_user_id[256];

    scanf("%s", i_user_id);

    printf("id size: %lu\n", strlen(i_user_id));

    pw = getpwnam(i_user_id);

    printf("cur user id: %s\n", pw->pw_name);

    if(strcmp(i_user_id, pw->pw_name) != 0) {
        perror("wrong id");
        exit(1);
    }
    else {
        printf("home dir: %s\n", pw->pw_dir);
        printf("shell: %s\n", pw->pw_shell);
        printf("success\n");
    }
}