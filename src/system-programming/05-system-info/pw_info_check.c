#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shadow.h>


int main() {
    struct spwd *spw;
    char i_user_id[256];

    scanf("%s", i_user_id);

    printf("id size: %lu\n", strlen(i_user_id));

    pw = getspnam(i_user_id);

    printf("cur user id: %s\n", spw->sp_namp);

    if(strcmp(i_user_id, spw->sp_namp) != 0) {
        perror("wrong id");
        exit(1);
    }
    else {
        printf("sp min: %d\n", spw->sp_min);
        printf("sp max: %d\n", spw->sp_max);
        printf("sp warn: %d\n", spw->sp_warn);
        printf("sp inactive: %d\n", spw->sp_inact);
        printf("success\n");
    }
}