#include <stdlib.h>
#include <stdio.h>


int main() {
    int ret;

    ret = remove("jo-2.txt");

    if (ret == -1) {
        perror("remove");
        exit(1);
    }

    printf("removed\n");
}