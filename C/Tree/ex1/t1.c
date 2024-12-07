#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

    No* head = initTree(10);

    appendValue(head, 2);

    appendValue(head, 12);
    appendValue(head, 5);
    appendValue(head, 1);
    appendValue(head, 3);

    printValues(head);

    printf("Hello World");
    return 0;
}