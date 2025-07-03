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

Node *deleteNode(Node *head, int value)
{
    if (head == NULL)
        return NULL;
    if (head != NULL && head->data == value)
    {
        Node *tmp = head;
        head = head->next;
        free(head);
    }

    Node *current = head;
    while (current->next != NULL)
    {
        if (current->next->data == value)
        {
            Node *tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        }
        else
            current = current->next;
    }
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
    for (int i = 1; i <= 5; i++)
    {
        tail->next = createNode(i);
        tail = tail->next;
    }
    displayList(head);
    head = deleteNode(head, 1);
    head = deleteNode(head, 5);
    displayList(head);
}