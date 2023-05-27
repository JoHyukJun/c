#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    if (rename("jo", "hj") == -1) {
        perror("rename err");
        exit(1);
    }
}