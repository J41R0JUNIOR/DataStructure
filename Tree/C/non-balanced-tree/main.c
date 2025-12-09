#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){
    No* head = initTree(1);

    appendValue(head, -1);
    appendValue(head, 2);
    appendValue(head, 5);
    appendValue(head, 4);
    appendValue(head, 6);
    appendValue(head, 3);

    removeValue(head, 3, NULL);

    printValues(head);
    return 0;
}