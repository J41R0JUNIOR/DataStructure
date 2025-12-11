typedef struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
} No;

No *initializeQueue(int value);
void enqueue(int value, No **tail);
void enqueueAt(int value, int at, No **head, No **tail);
void dequeue(No **head, No **tail);
void dequeueAt(int at, No **head, No **tail);
void printQueue(No *head);
void printReverseQueue(No *tail);