#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    // Inicializa a fila com o primeiro elemento
    No *head = initializeQueue(10);
    No *tail = head;

    printf("=== INITIAL QUEUE ===\n");
    printQueue(head);

    // Enqueue de elementos
    enqueue(20, &tail);
    enqueue(30, &tail);
    enqueue(12, &tail);

    printf("\n=== AFTER ENQUEUES ===\n");
    printQueue(head);

    // Dequeue do primeiro elemento
    dequeue(&head, &tail);

    printf("\n=== AFTER ONE DEQUEUE ===\n");
    printQueue(head);

    enqueueAt(100, 2, &head, &tail);

    printf("\n=== AFTER ENQUEUE AT POSITION 2 ===\n");
    printQueue(head);

    dequeueAt(4, &head, &tail);

    printf("\n=== AFTER DEQUEUE AT POSITION 4 ===\n");
    printQueue(head);

    printf("\n=== REVERSE QUEUE ===\n");
    printReverseQueue(tail);

    printf("\n\n=== FINAL QUEUE ===\n");
    printQueue(head);

    return 0;
}
