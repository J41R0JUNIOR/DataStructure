#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    No *head = initializeQueue(10);
    No *tail = head;
    
    printf("Initial Queue:");
    printQueue(head);

    enqueue(20, &tail);
    enqueue(30, &tail);
    enqueue(12, &tail);
    printf("\nQueue after enqueues:");
    printQueue(head);

    dequeue(&head, &tail);
    printf("\nQueue after one dequeue:");
    printQueue(head);

    enqueueAt(100, 2, &head, &tail);
    printf("\nQueue after enqueue at position:");
    printQueue(head);

    dequeueAt(4, &head, &tail);
    printf("\nQueue after dequeue at position:");
    printQueue(head);

    // printQueue(head);
    // printf("\n");
    // printReverseQueue(tail);

    return 0;
}