#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

No *initQueue(int value){
    No *head = malloc(sizeof(No));
    head->next = NULL;
    head->value = value;

    return head;
}

void printValuesInQueue(No *head){
    if(head != NULL){
        printf("%d ", head->value);
        printValuesInQueue(head->next);
    }
    return;
}

No *appendQueue(int value, No *head){
    No *newNode = malloc(sizeof(No));
    newNode->value = value; 
    newNode->next = NULL;
    
    head->next = newNode;

    return newNode;
} 

void appendQueueWithHead(int value, No *head){
    while(head->next != NULL){
        head = head->next;
    }

    No *newNode = malloc(sizeof(No *));
    newNode->value = value; 
    newNode->next = NULL;
    
    head->next = newNode;
}

void removeLast(No *head){
    No *prev ;

    if(head->next == NULL){
        removeFirst(head);
        return;
    }

    while (head->next != NULL){
        prev = head;
        head = head->next;
    }

    prev->next = NULL;
      free(head);
}

void addAt(No *head, int i, int value){
    No *prev, *newNode = malloc(sizeof(No *));

    for(int inc = 1; inc < i; inc++){
        if(head == NULL){
            printf("Incorrect value, maybe the i is to long for the queue \n");
            return;
        }

        prev = head;
        head = head->next;
    }

    newNode->next = prev->next;
    newNode->value = value;

    prev->next = newNode;
}

void removeAt(No *head, int i){
    No *prev;

    if(i == 1){
        removeFirst(head);
        return;
    }

   for(int inc = 1; inc < i; inc++){
        if(head->next == NULL){
            printf("Incorrect value, maybe the i is to long for the queue \n");
            return;
        }

        prev = head;
        head = head->next;
    }

    prev->next = head->next;
    free(head);
}

No *removeFirst(No* head){
    if(head->next != NULL){
        head->value = head->next->value;
        head->next = head->next->next;

        // head = head->next; FUNNY PART IS THAT THIS DOES NOT WORK
    }
}