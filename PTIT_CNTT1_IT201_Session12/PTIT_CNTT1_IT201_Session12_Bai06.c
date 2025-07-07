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

void printAtMid(Node *head, int *pos, int *value)
{
    if (head == NULL)
    {
        *pos = 0;
        *value = -1;
        return;
    }
    Node *slow = head;
    Node *fast = head;
    int idx = 1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        idx++;
    }
    *pos = idx;
    *value = slow->data;
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
    for (int i = 2; i <= 7; i++)
    {
        Node *newNode = createNode(i);
        current->next = newNode;
        newNode->pre = current;
        current = newNode;
    }
    displayList(head);
    int pos, value;
    printAtMid(head, &pos, &value);
    printf("Node %d: %d\n", pos, value);
}