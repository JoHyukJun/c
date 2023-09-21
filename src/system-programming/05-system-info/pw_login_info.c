#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shadow.h>
#include <time.h>


int main() {
    struct spwd *spw;
    time t;
    struct tm *tm;
    char i_user_id[256];

    scanf("%s", i_user_id);

    printf("id size: %lu\n", strlen(i_user_id));

    pw = getspnam(i_user_id);

    printf("cur user id: %s\n", spw->sp_namp);

    t = spw->sp_lstchg;
    tm = localtime(t);
    char s[64];

    if(strcmp(i_user_id, spw->sp_namp) != 0) {
        perror("wrong id");
        exit(1);
    }
    else {
        strftime(s, sizeof(s), "%Y-%m-%d", tm);
        printf("%s\n", s);
        printf("success\n");
    }
}