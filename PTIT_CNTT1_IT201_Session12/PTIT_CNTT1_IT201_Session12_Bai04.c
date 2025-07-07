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

Node *deleteAtEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    Node *cur = head;
    while (cur->next->next != NULL)
    {
        cur = cur->next;
    }
    Node *tmp = cur->next;
    cur->next = NULL;
    free(tmp);
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
    head = deleteAtEnd(head);
    displayList(head);
}