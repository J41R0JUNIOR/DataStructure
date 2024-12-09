#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

No *initTree(int value){
    No *head = malloc(sizeof(No));
    head->left = NULL;
    head->right = NULL;
    head->value = value;

    return head;
}

void printValues(No *head){
    if (head != NULL){
        printValues(head->left);
        printf("%d ", head->value);
        printValues(head->right);
    }
}

void appendValue(No *head, int value){
    if (head != NULL){
        if(value < head->value){
            addLeft(head->left, value, head);
        }

        if(value > head->value){
            addRight(head->right, value, head);
        }
    }
}

void addLeft(No *head, int value, No* prev){
    if(head != NULL){
        if(value < head->value){
            addLeft(head->left, value, head);
            return;
        }
        if(value > head->value){
            addRight(head->right, value, head);
            return;
        }
    }
    prev->left = createNode(value);
  
}

void addRight(No *head, int value, No* prev){
    if(head != NULL){
        if(value < head->value){
            addLeft(head->left, value, head);
            return;
        }
        if(value > head->value){
            addRight(head->right, value, head);
            return;
        }
    }
    prev->right = createNode(value);
}

No *createNode(int value){
    No *newNode = malloc(sizeof(No));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    return newNode;
}

void deleteNo(No *head, int value){
    if(head != NULL){
        if(value > head->value){
            deleteRightNo(head->right, value, head);
        }

        if(value < head->value){
            deleteLeftNo(head->left, value, head);
        }

        if(value == head->value){
            deleteHeadNo(head, value);
        }
    }
}