#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->pre = NULL;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("Node %d: %d\n", i, head->data);
        head = head->next;
        i++;
    }
}

int main()
{
    Node *head = createNode(1);
    Node *current = head;
    for (int i = 2; i <= 5; i++)
    {
        Node *newNode = createNode(i);
        current->next = newNode;
        newNode->pre = current;
        current = newNode;
    }
    displayList(head);
}