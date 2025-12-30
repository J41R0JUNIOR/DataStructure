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
        printf("\nEnqueue At Error:index %d\n out of bounds", at);
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

    if (node->prev == NULL)
        *head = node;
    if (node->next == NULL)
        *tail = node;
}

void dequeue(No **head, No **tail)
{
    if (*head == NULL)
    {
        printf("\nDequeue Error: Queue is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    *head = (*head)->next;
    (*head)->prev = NULL;
    free((*head)->prev);
}

void dequeueAt(int at, No **head, No **tail)
{
    if (*head == NULL)
    {
        printf("\nDequeue At Error:index %d\n out of bounds", at);
        return;
    }
    if (at > 0)
    {
        dequeueAt(at - 1, &((*head)->next), tail);
        return;
    }

    No *delete = (No *)malloc(sizeof(No));
    delete = *head;
    if (delete->prev != NULL)
        delete->prev->next = delete->next;
    if (delete->next != NULL)
        delete->next->prev = delete->prev;

    if (head == tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else if (delete == *head)
    {
        *head = delete->next;
    }
    else if (delete == *tail)
    {
        *tail = delete->prev;
    }

    free(delete);
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