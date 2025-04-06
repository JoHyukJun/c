#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>
#include "common.h"

typedef struct {
    long msg_type;
    int client_fd;
    char data[MAX_TEXT];
} MQResponse;

int main() {
    int req_qid = msgget(REQ_MQ_KEY, 0666);
    printf("[ECHO Service] Ready\n");

    while (1) {
        MQMessage req;
        msgrcv(req_qid, &req, sizeof(req) - sizeof(long), 1, 0);

        printf("[ECHO] Received from FD %d: %s\n", req.client_fd, req.data);

        MQResponse res;
        res.msg_type = req.client_fd;
        res.client_fd = req.client_fd;
        snprintf(res.data, MAX_TEXT, "ECHO: %s", req.data);

        msgsnd(req_qid, &res, sizeof(res) - sizeof(long), 0);
    }

    return 0;
}
