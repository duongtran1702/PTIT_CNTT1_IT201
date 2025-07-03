#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("Node %d: %d \n", i, head->data);
        head = head->next;
        i++;
    }
}

int main()
{
    Node *head = createNode(5);
    Node *tail = head;
    for (int i = 5; i >= 2; i--)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
}