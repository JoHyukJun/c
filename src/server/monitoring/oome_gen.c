#include <stdlib.h>


int main(void) {
    void* ptr;

    while (1) {
        ptr = malloc(1024 * 1024);

        if (ptr == NULL) {
            break;
        }
    }

    return 0;
}