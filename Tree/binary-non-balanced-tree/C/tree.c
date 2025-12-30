#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

No *initTree(int value)
{
    No *head = malloc(sizeof(No));
    head->left = NULL;
    head->right = NULL;
    head->value = value;

    return head;
}

void printValues(No *head)
{
    if (head != NULL)
    {
        printValues(head->left);
        printf("%d ", head->value);
        printValues(head->right);
    }
}

void appendValue(No *head, int value)
{
    if (head != NULL)
    {
        if (value < head->value)
        {
            addLeft(head->left, value, head);
        }

        if (value > head->value)
        {
            addRight(head->right, value, head);
        }
    }
}

void removeValue(No *head, int value, No *parent)
{
    if (head == NULL)
    {
        return;
    }

    if (value < head->value)
    {
        removeValue(head->left, value, head);
    }
    else if (value > head->value)
    {
        removeValue(head->right, value, head);
    }
    else
    {
        deleteNode(head, parent);
    }
}

void deleteNode(No *head, No *parent)
{
    if (head->left == NULL && head->right == NULL)
    {
        parent->left == head ? (parent->left = NULL) : (parent->right = NULL);
        free(head);
    }
    else if (head->left != NULL && head->right == NULL)
    {
        No *child = head->left;

        if (parent->left == head)
            parent->left = child;
        else
            parent->right = child;

        free(head);
    }
    else if (head->left == NULL && head->right != NULL)
    {
        No *child = head->right;

        if (parent->left == head)
            parent->left = child;
        else
            parent->right = child;

        free(head);
    }
    else
    {
        No *successor = head->right;
        No *successorParent = head;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        head->value = successor->value;

        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }

        free(successor);
    }
}

void addLeft(No *head, int value, No *prev)
{
    if (head != NULL)
    {
        if (value < head->value)
        {
            addLeft(head->left, value, head);
            return;
        }
        if (value > head->value)
        {
            addRight(head->right, value, head);
            return;
        }
    }
    prev->left = createNode(value);
}

void addRight(No *head, int value, No *prev)
{
    if (head != NULL)
    {
        if (value < head->value)
        {
            addLeft(head->left, value, head);
            return;
        }
        if (value > head->value)
        {
            addRight(head->right, value, head);
            return;
        }
    }
    prev->right = createNode(value);
}

No *createNode(int value)
{
    No *newNode = malloc(sizeof(No));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    return newNode;
}