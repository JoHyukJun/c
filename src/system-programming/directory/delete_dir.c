#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    if (rmdir("jo") == -1) {
        perror("jo");

        exit(1);
    }
}