#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>


int main() {
    struct passwd *pw;
    struct group *grp;
    char i_user_id[256];

    scanf("%s", i_user_id);

    printf("id size: %lu\n", strlen(i_user_id));

    pw = getpwnam(i_user_id);
    grp = getgrnam(i_user_id);

    printf("cur user id: %s\n", pw->pw_name);

    if(strcmp(i_user_id, pw->pw_name) != 0) {
        perror("wrong id");
        exit(1);
    }
    else {
        printf("first group: %d\n", (int)pw->pw_gid);
        printf("second group: %d\n", (int)grp->gr_gid);
        printf("success\n");
    }
}