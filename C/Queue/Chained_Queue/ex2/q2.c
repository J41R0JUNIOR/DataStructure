#include <stdio.h>
#include <stdlib.h>
#include "queue.h"




int main(){
     
     printf("Hello world\n");
     No *head = initQueue(100);
     No *n1 = appendQueue(1, head);
     No *n2 = appendQueue(2, n1);
     No *n3 = appendQueue(3, n2);
     printf("\nUsing what Maias used: ");
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


     addAt(head, 2, 314);
     printf("\n adding at specific position: ");
     printValuesInQueue(head); 

     return 0;
} 