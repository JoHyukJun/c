#include <stdio.h>

#define NUMBER 5
#define FAILED -1


int search_idx(const int v[], int idx[], int key, int n) {
    int i, count = 0;

    for (i = n - 1; i >= 0; i--) {
        if (v[i] == key)
            idx[count++] = i;
    }

    return count;
}

int main(void) {
    int i, ky, num;
    int vx[NUMBER];
    int pt[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("vx[%d]: ", i);
        scanf("%d", &vx[i]);
    }

    printf("key val: ");
    scanf("%d", &ky);

    if ((num = search_idx(vx, pt, ky, NUMBER)) == 0)
        puts("search fail");
    else {
        printf("%d : %d\n", ky, num);

        for (i = 0; i < num; i++) {
            printf("vx[%d] = %d\n", pt[i], vx[pt[i]]);
        }
    }

    return 0;
}