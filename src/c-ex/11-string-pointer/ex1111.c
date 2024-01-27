#include <stdio.h>
#include <string.h>


int is_whitespace(int ch) {
    return ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v';
}

long strtol(const char *nptr) {
    int sign = 1;
    long x = 0;

    while (is_whitespace(*nptr)) {
        nptr++;
    }

    switch (*nptr)
    {
    case '+':
        nptr++;
        break;
    case '-':
        nptr++;
        sign = -1;
        break;
    }

    for (x = 0; *nptr >= '0' && *nptr <= '9'; nptr++) {
        x = x * 10 + (*nptr - '0');
    }

    return sign * x;
}

int strtoi(const char *nptr) {
    return (int)strtol(nptr);
}

double strtof(const char *nptr) {
    int sign = 1;
    double x = 0;
    double dec;

    while (is_whitespace(*nptr)) {
        nptr++;
    }

    switch (*nptr)
    {
    case '+':
        nptr++;
        break;
    case '-':
        nptr++;
        sign = -1;
        break;
    }

    for (x = 0.0; *nptr >= '0' && *nptr <= '9'; nptr++) {
        x = x * 10.0 + (*nptr - '0');
    }

    if (*nptr == '.') {
        nptr++;
    }

    for (dec = 1.0; *nptr >= '0' && *nptr <= '9'; nptr++) {
        x = x + (dec /= 10.0) * (*nptr - '0');
    }

    if (*nptr == 'E' || *nptr == 'e') {
        int exp;
        int sign = 1;

        switch (*++nptr)
        {
        case '+':
            nptr++;
            break;
        case '-':
            nptr++;
            sign = -1;
            break;
        }

        for (exp = 0; *nptr >= '0' && *nptr <= '9'; nptr++) {
            exp = 10 * exp + (*nptr - '0');
        }

        switch (sign)
        {
        case 1:
            while (exp-- > 0) x *= 10.0;
            break;
        case -1:
            while (exp-- > 0) x /= 10.0;
            break;
        }
    }

    return sign * x;
}

int main(void) {
    char s1[128], s2[10], s3[10];
    long l1;
    int i1;
    double f1;

    strcpy(s1, "123456789123");
    printf("s1 = %s\n", s1);
    l1 = strtol(s1);
    printf("l1 = %ld\n", l1);

    strcpy(s2, "1234");
    printf("s2 = %s\n", s2);
    i1 = strtoi(s2);
    printf("i1 = %d\n", i1);

    strcpy(s3, "12.34");
    printf("s3 = %s\n", s3);
    f1 = strtof(s3);
    printf("f1 = %lf\n", f1);

    return 0;
}