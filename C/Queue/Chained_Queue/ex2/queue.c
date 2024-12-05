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

No *removeLast(No *head){
    No *prev = malloc(sizeof(No *));

    while (head->next != NULL){
        prev = head;
        head = head->next;
    }

    prev->next = NULL;
}