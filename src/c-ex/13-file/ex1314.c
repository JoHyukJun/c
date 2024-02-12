#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 16


int main(void) {
    int n;
    unsigned char buf[BUF_SIZE];
    FILE *sfp;
    FILE *dfp;
    char sname[FILENAME_MAX];
    char dname[FILENAME_MAX];

    printf("복사할 내용이 있는 파일 이름: "); scanf("%s", sname);
    printf("내용을 복사해 넣을 파일 이름: "); scanf("%s", dname);

    if ((sfp = fopen(sname, "rb")) == NULL) {
        printf("\a복사할 내용이 있는 파일을 열 수 없습니다.");
    }
    else {
        if ((dfp = fopen(dname, "wb")) == NULL) {
            printf("\a내용을 복사해 넣을 파일을 열 수 없습니다.");
        }
        else {
            unsigned long count = 0;

            while (1) {
                int i;

                if ((n = fread(buf, 1, BUF_SIZE, sfp)) != 0) {
                    fwrite(buf, 1, n, dfp);
                    
                    printf("%08lX", count);

                    for (i = 0; i < n; i++) {
                        printf("%02X", (unsigned)buf[i]);
                    }

                    if (n < 16) {
                        for (i = n; i < 16; i++) {
                            printf("    ");
                        }
                    }

                    for (i = 0; i < n; i++) {
                        putchar(isprint(buf[i]) ? buf[i] : '.');
                    }
                    
                    putchar('\n');

                    count += n;
                }

                if (n < BUF_SIZE) {
                    break;
                }
            }

            fclose(dfp);
        }

        fclose(sfp);
    }

    return 0;
}