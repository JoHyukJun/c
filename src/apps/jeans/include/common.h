// common.h
#ifndef COMMON_H
#define COMMON_H

#define MAX_TEXT 512
#define REQ_MQ_KEY 2222


typedef struct {
    long msg_type;          // 메시지 타입 (예: 1)
    char service[32];       // 서비스명 (예: ECHO)
    char data[MAX_TEXT];    // 실제 요청 데이터
    int client_fd;          // TCP 소켓 FD (서버에서 식별용)
} MQMessage;

#endif
