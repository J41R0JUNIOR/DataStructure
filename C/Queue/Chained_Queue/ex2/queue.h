typedef struct Node {
    struct Node *next;
    int value;
} No;

No *initQueue(int value);  
No *appendQueue(int value, No *head);
void appendQueueWithHead(int value, No *head);
void printValuesInQueue(No *head);
 No *removeLast(No *head);