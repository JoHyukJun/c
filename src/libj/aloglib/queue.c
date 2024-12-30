#include "queue.h"

int print_queue()
{
    printf("QUEUE\n");

    return (0);
}

Queue *create_queue()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    if (queue == NULL)
    {
        perror("malloc");

        return NULL;
    }
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

QueueNode *create_queue_node(data)
int data;
{
    QueueNode *node = (QueueNode*)malloc(sizeof(QueueNode));

    if (node == NULL)
    {
        perror("malloc");

        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void enqueue(queue, data)
Queue *queue;
int data;
{
    QueueNode *node = create_queue_node(data);

    if (node == NULL) return;

    if (queue->head == NULL)
    {
        queue->head = node;
        queue->tail = node;

        return;
    }

    queue->tail->next = node;
    queue->tail = node;
}

int dequeue(queue, data)
Queue *queue;
int *data;
{
    if (queue->head == NULL)
    {
        return (0);
    }

    QueueNode *node = queue->head;
    *data = node->data;

    queue->head = node->next;
    free(node);

    return (1);
}

void delete_queue(queue)
Queue *queue;
{
    QueueNode *current = queue->head;
    QueueNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}

int is_empty(queue)
Queue *queue;
{
    return (queue->head == NULL);
}

int get_queue_size(queue)
Queue *queue;
{
    int size = 0;
    QueueNode *current = queue->head;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}

int print_queue_node(node)
QueueNode *node;
{
    printf("%d ", node->data);

    return (0);
}

void print_queue_all(queue)
Queue *queue;
{
    QueueNode *current = queue->head;

    while (current != NULL)
    {
        print_queue_node(current);
        current = current->next;
    }

    printf("\n");
}

int search_queue_node(queue, data)
Queue *queue;
int data;
{
    QueueNode *current = queue->head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return (1);
        }

        current = current->next;
    }

    return (0);
}

int delete_queue_node(queue, data)
Queue *queue;
int data;
{
    QueueNode *current = queue->head;
    QueueNode *prev = NULL;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (prev == NULL)
            {
                queue->head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);

            return (1);
        }

        prev = current;
        current = current->next;
    }

    return (0);
}

int delete_queue_all(queue)
Queue *queue;
{
    QueueNode *current = queue->head;
    QueueNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    queue->head = NULL;
    queue->tail = NULL;

    return (1);
}

int get_queue_front(queue)
Queue *queue;
{
    if (queue->head == NULL)
    {
        return (-1);
    }

    return queue->head->data;
}

int get_queue_rear(queue)
Queue *queue;
{
    if (queue->tail == NULL)
    {
        return (-1);
    }

    return queue->tail->data;
}
