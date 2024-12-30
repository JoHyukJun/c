#include "stack.h"


int print_stack()
{
    printf("STACK\n");

    return (0);
}

Stack *create_stack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL)
    {
        perror("malloc");

        return NULL;
    }
    stack->top = NULL;

    return stack;
}

StackNode *create_stack_node(data)
int data;
{
    StackNode *node = (StackNode*)malloc(sizeof(StackNode));

    if (node == NULL)
    {
        perror("malloc");

        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void push_stack(stack, data)
Stack *stack;
int data;
{
    StackNode *node = create_stack_node(data);

    if (node == NULL) return;

    if (stack->top == NULL)
    {
        stack->top = node;

        return;
    }

    node->next = stack->top;
    stack->top = node;
}

int pop_stack(stack)
Stack *stack;
{
    if (stack->top == NULL)
    {
        return (-1);
    }

    StackNode *node = stack->top;
    int data = node->data;

    stack->top = node->next;
    free(node);

    return data;
}

int peek_stack(stack)
Stack *stack;
{
    if (stack->top == NULL)
    {
        return (-1);
    }

    return stack->top->data;
}

int delete_stack(stack)
Stack *stack;
{
    StackNode *current = stack->top;
    StackNode *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);

    return (1);
}

int search_stack(stack, data)
Stack *stack;
int data;
{
    StackNode *current = stack->top;

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
