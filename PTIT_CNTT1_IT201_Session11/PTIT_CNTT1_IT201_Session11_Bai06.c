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
    printf("NULL <- ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->next != NULL)
            printf("<--> ");
        head = head->next;
    }
    printf("-> NULL\n");
}

void deleteNodeAtHead(Node **head)
{
    if (*head == NULL)
        return;
    Node *tmp = *head;
    if ((*head)->next == NULL)
        *head = NULL;
    else
    {
        *head = (*head)->next;
        (*head)->pre = NULL;
    }
    free(tmp);
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
    deleteNodeAtHead(&head);
    displayList(head);
}