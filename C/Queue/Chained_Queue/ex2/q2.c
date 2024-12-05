#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
     
     printf("Hello world\n");
     No *head = initQueue(100);
     No *n1 = appendQueue(1, head);
     No *n2 = appendQueue(2, n1);
     No *n3 = appendQueue(3, n2);
     printf("\nAppend the way Maias used to do: ");
     printValuesInQueue(head); 

     removeLast(head);
     removeLast(head);
     printf("\nQueue cleared: ");
     printValuesInQueue(head); 


     appendQueueWithHead(10, head);
     appendQueueWithHead(20, head);
     appendQueueWithHead(30, head);
     appendQueueWithHead(40, head);
     printf("\nNow append with head: ");
     printValuesInQueue(head); 

     printf("\nadding at specific position: ");
     addAt(head, 20, 314);
     printValuesInQueue(head);

     printf("\nremoving at specific position: ");
     removeAt(head,1);
     printValuesInQueue(head);

     return 0;
} 