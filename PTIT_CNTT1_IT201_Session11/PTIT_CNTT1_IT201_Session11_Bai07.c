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
void displayListReverse(Node *tail)
{
    printf("NULL <- ");
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        if (tail->pre != NULL)
        {
            printf("<--> ");
        }
        tail = tail->pre;
    }
    printf("-> NULL\n");
}
int lengthList(Node *head)
{
    int i = 0;
    while (head != NULL)
    {
        i++;
        head = head->next;
    }
    return i;
}
Node *insertNode(Node *head, int pos, int value)
{
    int length = lengthList(head);
    if (pos > length + 1 || pos < 1)
        return head;
    Node *newNode = createNode(value);
    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->pre = newNode;
        return newNode;
    }
    Node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    if (newNode->next != NULL)
        current->next->pre = newNode;
    newNode->pre = current;
    current->next = newNode;
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
    head = insertNode(head, 6, 6);
    head = insertNode(head, 3, 4);
    displayList(head);
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    displayListReverse(tail);
}