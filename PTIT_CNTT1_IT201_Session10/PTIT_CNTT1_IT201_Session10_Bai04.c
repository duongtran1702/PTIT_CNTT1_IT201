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

Node *deleteNodeAtEnd(Node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    Node *tmp = current->next;
    current->next = NULL;
    free(tmp);
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
    head = deleteNodeAtEnd(head);
    displayList(head);
}