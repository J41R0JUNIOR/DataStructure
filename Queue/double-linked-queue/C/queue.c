#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

No *initializeQueue(int value)
{
    No *node = (No *)malloc(sizeof(No));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void enqueue(int value, No **tail)
{
    No *node = (No *)malloc(sizeof(No));
    node->value = value;
    node->next = NULL;
    node->prev = *tail;
    (*tail)->next = node;

    *tail = node;
}

void enqueueAt(int value, int at, No **head, No **tail)
{
    if (*head == NULL)
    {
        printf("\nOut of bounds\n");
        return;
    }
    if (at > 0)
    {
        enqueueAt(value, at - 1, &((*head)->next), tail);
        return;
    }
   
    No *node = (No *)malloc(sizeof(No));
    node->value = value;
    node->next = *head;
    node->prev = (*head)->prev;
    (*head)->prev->next = node;
    (*head)->prev = node;

    if (node->prev == NULL) *head = node;
    if (node->next == NULL) *tail = node;
}

void dequeue(No **head, No **tail)
{
    if (*head == NULL)
    {
        printf("\nQueue is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        printf("\nDequeued: %d\n", (*head)->value);
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    
        printf("\nDequeued: %d\n", (*head)->value);
        *head = (*head)->next;
        (*head)->prev = NULL;
        free((*head)->prev);
    
}

void dequeueAt(int at, No **head, No **tail)
{
    if (*head == NULL)
    {
        printf("\nOut of bounds\n");
        return;
    }
    if (at > 0)
    {
        dequeueAt(at - 1, &((*head)->next), tail);
        return;
    }

    // dequeue logic
}

void printQueue(No *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d ", head->value);
    printQueue(head->next);
}

void printReverseQueue(No *tail)
{
    if (tail == NULL)
    {
        return;
    }

    printf("%d ", tail->value);
    printReverseQueue(tail->prev);
}