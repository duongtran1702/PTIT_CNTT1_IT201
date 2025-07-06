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
Node *deleteNode(Node *head, int pos)
{
    int length = lengthList(head);
    if (pos < 1 || pos > length)
        return head;
    if (pos == 1)
    {
        Node *tmp = head;
        head = head->next;
        if (head != NULL)
            head->pre = NULL;
        free(tmp);
        return head;
    }

    Node *current = head;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
    }

    Node *tmp = current->next;
    if (current->next->next != NULL)
        current->next->next->pre = current;
    current->next = current->next->next;
    free(tmp);
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
    head = deleteNode(head, 3);
    displayList(head);
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    displayListReverse(tail);
}