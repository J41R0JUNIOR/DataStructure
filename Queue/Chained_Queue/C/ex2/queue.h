typedef struct Node {
    struct Node *next;
    int value;
} No;

void printValuesInQueue(No *head);

No *initQueue(int value);  

No *appendQueue(int value, No *head);
void appendQueueWithHead(int value, No *head);
void addAt(No *head, int i, int value);


void removeLast(No *head);
void removeAt(No *head, int i);
No *removeFirst(No* head);