#include <stdio.h>


int scan_int(void) {
    int temp;

    printf("no: ");
    scanf("%d", &temp);

    return temp;
}

int ave_of(int a, int b) {
    return (a + b) / 2;
}

int main(void) {
    int n1 = scan_int();
    int n2 = scan_int();
    int n3 = scan_int();
    int ave;

    if ((ave = ave_of(n1, n2)) == 0) {
        printf("ave val = 0\n");
    }
    else if (ave > 0) {
        printf("ave val = %d\n", ave);
    }
    else {
        printf("ave val = %d\n", ave);
    }

    if ((ave = ave_of(n1, n3)) == 0) {
        printf("ave val = 0\n");
    }
    else if (ave > 0) {
        printf("ave val = %d\n", ave);
    }
    else {
        printf("ave val = %d\n", ave);
    }

    if ((ave = ave_of(n2, n3)) == 0) {
        printf("ave val = 0\n");
    }
    else if (ave > 0) {
        printf("ave val = %d\n", ave);
    }
    else {
        printf("ave val = %d\n", ave);
    }

    return 0;
}