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
Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
        return newNode;
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->pre = current;
    return head;
}

void displayList(Node *head)
{
    printf("NULL <-");
    while (head != NULL)
    {
        printf(" %d ", head->data);
        if (head->next != NULL)
            printf("<-->");
        head = head->next;
    }
    printf("-> NULL\n");
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
    head = insertAtEnd(head, 6);
    displayList(head);
}