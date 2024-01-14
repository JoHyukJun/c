#include <stdio.h>

#define LEN 128


int str_length(const char s[]) {
    int len = 0;

    while (s[len])
        len++;

    return len;
}

void rev_string(char s[]) {
    int i, len = str_length(s);

    for (i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void rev_strings(char s[][LEN], int n) {
    int i;

    for (i = 0; i < n; i++)
        rev_string(s[i]);
}

void put_strary(const char s[][LEN], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("s[%d] = \"%s\"\n", i, s[i]);
}

int main(void) {
    char cs[][LEN] = {"SEC", "ABC", "12345"};

    rev_strings(cs, 3);

    put_strary(cs, 3);

    return 0;
}