#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    int value;
} No;

No* appendValue(int value, No *no){
   
    No *newNo = (No *)malloc(sizeof(No));
    newNo->value = value;
    newNo->next = NULL;
    no->next = newNo;

    return newNo;
}

void printList(No *no){
    if (no->next != NULL){
        printf("%d\n", no->value);
        printList(no->next);
    } else {
        printf("%d\n", no->value);
    }
}

No* removeValue(int value, No *no, No *prev){
    if(no == NULL){
        return NULL;
    }

    if(no->value != value){
        return removeValue(value, no->next, no);
    }

    if(no->value == value){
        prev->next = no->next;
        free(no);
    }
}

int main() {
    printf("Hello, World!\n");

    No* head = (No *)malloc(sizeof(No));
    head->value = 1;
    head->next = NULL;

    No* n1 = appendValue(2, head);
    No* n2 = appendValue(3, n1);
    No* n3 = appendValue(4, n2);
    No* n4 = appendValue(5, n3);
    

    printList(head);

    removeValue(3, head, NULL); 

    printList(head);
 

    return 0;
}