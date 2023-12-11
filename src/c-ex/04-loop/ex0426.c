#include <stdio.h>


int main(void)
{
    int no, width;

    printf("no: ");
    scanf("%d", &no);
    printf("width: ");
    scanf("%d", &width);

    if (no > 0) {
        int i, j;
        int rem = no % width;
        int wid = width / 2;
        int odd = width % 2;

        for (i = 0; i < no / width / 2; i++) {
            for (j = 0; j < wid; j++) {
                printf("+-");
            }
            putchar('\n');
            for (j = 0; j < wid; j++) {
                printf("-+");
            }
            putchar('\n');
        }

        if (no / width % 2) {
            for (i = 0; i < wid; i++) {
                printf("+-");
            }
            putchar('\n');
        }

        if (rem > 0) {
            switch (no / width % 2)
            {
            case 0:
                for (j = 0; j < rem / 2; j++) {
                    printf("+-");
                }

                if (rem % 2) putchar('+');
                break;
            
            case 1:
                for (j = 0; j < rem / 2; j++) {
                    printf("-+");
                }

                if (rem % 2) putchar('-');
                break;
            }
            putchar('\n');
        }
    }

    return 0;
}