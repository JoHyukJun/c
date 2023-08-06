#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    FILE *rfp;
    int n;
    char buf[BUFSIZ];
    char *input_file_name;
    char *search_node;

    input_file_name = argv[1];
    search_node = argv[2];

    if ((rfp = fopen(input_file_name, "r")) == NULL) {
        perror("fopen");
        exit(1);
    }

    printf("SEARCH NODE: %d\n", (unsigned char)search_node[0]);

    while((n = fgetc(rfp)) != EOF) {
        printf("CUR TARGET: %d\n", n);
        if (n == (unsigned char)search_node[0]) {
            printf("TRUE\n");

            return 0;
        }
    }

    printf("FALSE\n");

    fclose(rfp);
}