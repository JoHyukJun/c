#include <stdio.h>


int main(void)
{
    int area;
    int height;

    printf("area: ");
    scanf("%d", &area);

    for (height = 1; height < area; height++) {
        if (height * height > area) break;

        if (area % height != 0) continue;

        printf("%d x %d\n", height, area / height);
    }

    return 0;
}