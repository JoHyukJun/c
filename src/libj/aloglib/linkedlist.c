#include "linkedlist.h"


int print_linkedlist()
{
    printf("LINKEDLIST\n");

    return (0);
}

LinkedList *create_linked_list()
{
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));

    if (list == NULL)
    {
        perror("malloc");

        return NULL;
    }
    list->head = NULL;

    return list;
}

LinkedListNode *create_linked_list_node(data)
int data;
{
    LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));

    if (node == NULL)
    {
        perror("malloc");

        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void insert_linked_list_node(list, data)
LinkedList *list;
int data;
{
    LinkedListNode *node = create_linked_list_node(data);

    if (node == NULL) return;

    if (list->head == NULL)
    {
        list->head = node;

        return;
    }

    LinkedListNode *current = list->head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
}

void print_linked_list(list)
LinkedList *list;
{
    LinkedListNode *current = list->head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void delete_linked_list(list)
LinkedList *list;
{
    LinkedListNode *current = list->head;
    LinkedListNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}
