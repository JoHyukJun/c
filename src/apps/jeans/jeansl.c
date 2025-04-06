#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/select.h>
#include "common.h"

typedef struct {
    long msg_type;
    int client_fd;
    char data[MAX_TEXT];
} MQResponse;

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(9999),
        .sin_addr.s_addr = INADDR_ANY
    };
    bind(server_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(server_sock, 5);

    printf("[TCP Server] Listening on port 9999...\n");

    int req_qid = msgget(REQ_MQ_KEY, IPC_CREAT | 0666);

    fd_set readfds;
    int maxfd = server_sock;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(server_sock, &readfds);

        // select로 다중 소켓 처리
        select(maxfd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(server_sock, &readfds)) {
            int client_sock = accept(server_sock, NULL, NULL);
            if (fork() == 0) {
                // 자식 프로세스: 요청 수신 후 MQ로 전송
                close(server_sock);

                char buffer[MAX_TEXT];
                read(client_sock, buffer, MAX_TEXT);
                char* service = strtok(buffer, ":");
                char* payload = strtok(NULL, "");

                MQMessage msg;
                msg.msg_type = 1;
                msg.client_fd = client_sock;
                strncpy(msg.service, service, sizeof(msg.service));
                strncpy(msg.data, payload, MAX_TEXT);

                msgsnd(req_qid, &msg, sizeof(msg) - sizeof(long), 0);

                // 응답 기다림
                MQResponse res;
                msgrcv(req_qid, &res, sizeof(res) - sizeof(long), client_sock, 0);

                write(client_sock, res.data, strlen(res.data) + 1);
                close(client_sock);
                exit(0);
            }
            close(client_sock); // 부모는 소켓 닫기
        }
    }

    return 0;
}
