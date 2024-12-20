#ifndef __MQLIB__
#define __MQLIB__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int print_mqlib();
int mq_open(key_t key);
int mq_delete(int mqid);
int mq_send(int mqid, const char *msg, int len);
int mq_recv(int mqid, char *msg, int len);
int mq_send_block(int mqid, const char *msg, int len);
int mq_recv_block(int mqid, char *msg, int len);
int mq_send_nowait(int mqid, const char *msg, int len);
int mq_recv_nowait(int mqid, char *msg, int len);


#endif