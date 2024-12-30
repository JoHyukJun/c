#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct LinkedListNode {
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode *head;
} LinkedList;

#endif