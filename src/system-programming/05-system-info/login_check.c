#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char input_id[256];

    scanf("%s", input_id);

    printf("id size: %lu\n", strlen(input_id));

    if(strlen(input_id) > sysconf(_SC_LOGIN_NAME_MAX)) {
        perror("id len error");
        exit(1);
    }

    printf("success\n");
}