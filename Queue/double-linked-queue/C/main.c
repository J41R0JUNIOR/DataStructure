#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    No *head = initializeQueue(10);
    No *tail = head;
    
    enqueue(20, &tail);
    enqueue(30, &tail);
    enqueue(12, &tail);

    dequeue(&head, &tail);
    enqueueAt(25, 1, &head, &tail);
    dequeueAt(1, &head, &tail);

    printQueue(head);
    printf("\n");
    printReverseQueue(tail);

    return 0;
}