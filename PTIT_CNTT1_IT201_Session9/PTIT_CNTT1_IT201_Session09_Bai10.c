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

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

Node *swapPairs(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = head->next;
    Node *tmp = NULL;
    Node *first = head;
    Node *second = NULL;

    while (first != NULL && first->next != NULL)
    {
        second = first->next;
        first->next = second->next;
        second->next = first;

        if (tmp != NULL)
            tmp->next = second;

        tmp = first;
        first = first->next;
    }
    return newHead;
}

int main()
{
    Node *head = createNode(1);
    Node *tail = head;
    for (int i = 2; i <= 6; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
    printf("\n");
    head = swapPairs(head);
    displayList(head);
}