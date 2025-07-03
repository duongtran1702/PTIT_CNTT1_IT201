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
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node *addNodeAtEnd(Node *head, int value)
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
    return head;
}
int main()
{
    Node *head = createNode(1);
    Node *tail = head;
    for (int i = 2; i <= 5; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
    head = addNodeAtEnd(head, 6);
    displayList(head);
}