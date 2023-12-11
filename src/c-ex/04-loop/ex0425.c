#include <stdio.h>


int main(void)
{
    int no, width;

    printf("*: ");
    scanf("%d", &no);
    printf("width: ");
    scanf("%d", &width);

    if (no > 0) {
        int i, j;
        int rem = no % width;

        for (i = 0; i < no / width; i++) {
            for (j = 0; j < width; j++) {
                putchar('*');
            }
            putchar('\n');
        }

        if (rem > 0) {
            for (i = 0; i < rem; i++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    return 0;
}