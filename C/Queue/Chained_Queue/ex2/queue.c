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
}

No *appendQueue(int value, No *head){

    No *newNode = malloc(sizeof(No));
    newNode->value = value;
    newNode->next = NULL;
    
    head->next = newNode;

    return newNode;
} 

void appendQueueWithHead(int value, No *head){
    if(head != NULL){
       head = head->next;
    }

    No *newNode = malloc(sizeof(No*));
    newNode->value = value;
    newNode->next = NULL;

    head->next = newNode;
}