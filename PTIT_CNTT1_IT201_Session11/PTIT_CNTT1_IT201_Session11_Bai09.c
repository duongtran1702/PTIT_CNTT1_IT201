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
Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *current = head;
    Node *tmp = NULL;

    while (current != NULL)
    {
        tmp = current->pre;
        current->pre = current->next;
        current->next = tmp;

        current = current->pre;
    }
    if (tmp != NULL)
        head = tmp->pre;
    return head;
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
    head = reverseList(head);
    displayList(head);
}