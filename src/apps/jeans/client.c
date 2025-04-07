#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_TEXT 512

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(9999);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    char service[32], data[MAX_TEXT], buffer[MAX_TEXT];

    printf("Enter service (ECHO): ");
    scanf("%s", service);
    getchar();
    printf("Enter message: ");
    fgets(data, MAX_TEXT, stdin);
    data[strcspn(data, "\n")] = 0;

    snprintf(buffer, MAX_TEXT, "%s:%s", service, data);
    write(sock, buffer, strlen(buffer) + 1);

    read(sock, buffer, MAX_TEXT);
    printf("Response from server: %s\n", buffer);

    close(sock);
    return 0;
}
