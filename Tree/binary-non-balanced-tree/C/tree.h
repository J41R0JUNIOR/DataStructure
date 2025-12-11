typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}No;

void printValues(No* head);
No* initTree(int value);
void appendValue(No* head, int value);
void removeValue(No* head, int value, No* parent);
void deleteNode(No *head, No *parent);
void addLeft(No *head, int value, No* prev);
void addRight(No *head, int value, No* prev);
No *createNode(int value);
