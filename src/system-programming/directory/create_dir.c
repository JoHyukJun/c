#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    if (mkdir("jo") == -1) {
        perror("jo");

        exit(1);
    }
}