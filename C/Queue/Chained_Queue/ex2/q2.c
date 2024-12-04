#include <stdio.h>
#include <stdlib.h>
#include "queue.h"




int main(){
     
     printf("Hello world\n");
     No *queue = initQueue(1);

     No *n1 = appendQueue(1, queue);
     No *n2 = appendQueue(2, n1);
     No *n3 = appendQueue(3, n2);

     printf("Queue initialized with value: %d\n", queue->value);

     printValuesInQueue(queue);
     printf("\n");

     appendQueueWithHead(50, queue);
     printValuesInQueue(queue);

     return 0;
} 