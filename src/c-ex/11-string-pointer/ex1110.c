#include <stdio.h>
#include <string.h>

int main(void) {
    char str[128];

    printf("문자열을 입력하세요: ");
    scanf("%s", str);

    printf("문자열 %s 의 길이는 %u 입니다.\n", str, (unsigned)strlen(str));

    char s1[10], s2[10], s3[10];
    char *x = "XXXXXXXXX";

    strcpy(s1, "ABC");
    printf("s1 = %s\n", s1);
    printf("s1 = %s\n", strcpy(s1, "1234"));

    strcpy(s2, strcpy(s1, "HAL"));
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    strcpy(s3, x);
    strncpy(s3, "12345", 3);
    printf("s3 = %s\n", s3);

    strcpy(s3, x);
    strncpy(s3, "12345", 5);
    printf("s3 = %s\n", s3);

    strcpy(s3, x);
    strncpy(s3, "12345", 7);
    printf("s3 = %s\n", s3);

    strcpy(s3, x);
    strncpy(s3, "1234567890", 9);
    printf("s3 = %s\n", s3);

    char s4[10];
    char *xx = "ABC";

    strcpy(s4, "QWE");
    strcat(s4, "RTY");
    printf("s4 = %s\n", s4);

    strcpy(s4, xx);
    strncat(s4, "123", 1);
    printf("s4 = %s\n", s4);

    strcpy(s4, xx);
    strncat(s4, "123", 3);
    printf("s4 = %s\n", s4);

    strcpy(s4, xx);
    strncat(s4, "12345", 5);
    printf("s4 = %s\n", s4);

    strcpy(s4, xx);
    strncat(s4, "123456789", 5);
    printf("s4 = %s\n", s4);

    char s5[128];

    puts("\"ABCDE\" 와 비교를 수행합니다.");
    puts("\"XXXXX\" 로 종료합니다.");

    while (1)
    {
        printf("\n문자열 s5: ");
        scanf("%s", s5);

        if (strcmp(s5, "XXXXX") == 0) {
            break;
        }

        printf("strcmp(\"ABCDE\", s5) = %d\n", strcmp("ABCDE", s5));
        printf("strncmp(\"ABCDE\", s5, 3) = %d\n", strncmp("ABCDE", s5, 3));
    }
    

    return 0;
}