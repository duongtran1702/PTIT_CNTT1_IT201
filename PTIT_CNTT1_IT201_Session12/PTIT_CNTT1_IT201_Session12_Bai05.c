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

Node *deleteNode(Node *head, int x)
{
    Node *cur = head;
    if (cur == NULL)
        return cur;
    if (cur->data == x)
    {
        Node *tmp = cur;
        cur = cur->next;
        if (cur != NULL)
            cur->pre = NULL;
        free(tmp);
        head = cur;
    }

    while (cur->next != NULL)
    {
        if (cur->next->data == x)
        {
            Node *tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next != NULL)
                tmp->next->pre = cur;
            free(tmp);
        }
        else
            cur = cur->next;
    }
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
    for (int i = 1; i <= 4; i++)
    {
        Node *newNode = createNode(i);
        current->next = newNode;
        newNode->pre = current;
        current = newNode;
    }
    displayList(head);
    head=deleteNode(head, 3);
    displayList(head);
}